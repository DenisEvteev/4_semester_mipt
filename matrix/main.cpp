#include "matrix.h"

/*This moment the design of the program is simplified to multiplication just quadratic matrices
 TODO : to add support to multiply matrices of arbitary size (only one usual restriction) */


/* FIXME : I have facilitated the design of matrix multiplication very much.
 *  The fact that has caused it is the strict requirement for time of execution with different number of threads, which
 *  was given to me from the customer.
 *  In case when we have a big serial time of code [50%] we won't have any opportunity to improve speedup more than
 *  [50%] what is unacceptable!
 *  So, I've decided to fill the left and right matrices with similar values hence I don't do transpose operation
 *  for right matrix due to it's a quadratic one, so it will be the same. And I use function
 *  parallel_matrix_multiplication which is cache-friendly.*/

thr::matrix<int> left, right, result;

const unsigned n = 2048;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void change_next_index_cpu(const unsigned &whole, unsigned &remainder_np, unsigned &current_number_proc,
						   int &save_current_number_for_proc, int &is_remainder_decreased);
void *run(void *arg);
//void *stupid_routine(void* arg);

namespace thr
{
void distribute_relative_cpu(const unsigned cpu);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "error : bad amount of arguments!\n";
		exit(EXIT_FAILURE);
	}
	unsigned threads = std::atoi(argv[1]);
	assert(threads != 0);
	if (threads > n) {
		std::cerr << "error : too big number of threads\n";
		exit(EXIT_FAILURE);
	}
	//--------FILL MATRICES WITH SOME INITIAL VALUES ---- SERIAL PART OF CODE----------//
	left.init_matrix(n, 1);
	right.init_matrix(n, 1); // assume that it is a transposed matrix
	result.init_matrix(n, 0);
	//-------------------------------------------------------------------------------//
	unsigned processors = sysconf(_SC_NPROCESSORS_CONF);
	unsigned save_start = 0, current_number_proc = 0;
	/*Excess variable show the size of elements which should be spread between threads before the last one */
	unsigned step = n / threads, excess = n - step * (threads - 1) - step;
	unsigned remainder_np = threads % processors, whole = threads / processors;
	int is_remainder_decreased = 0, save_current_number_for_proc = 1;

#ifdef DEBUG
	/*I'm going to use this vector to save pthread identificators for joining all the pthreads at the end of
	 * the process to compare the result matrix to the expected matrix*/
	std::vector<pthread_t> ids(threads);

#define id(i) ( &ids[i] )

#else
	pthread_t ptid;
#define id(i) ( &ptid )

#endif
	int ret;
	for (unsigned thr = 0; thr < threads; ++thr) {
		/*Prepare the argument to the thread start function*/
		bound_t *bd = nullptr;
		if (thr == threads - 1)
			bd = new bound_t(save_start, n - 1);
		else {
			if (excess > 1) {
				bd = new bound_t(save_start, save_start + step);
				--excess;
			}
			else
				bd = new bound_t(save_start, save_start + step - 1);
			save_start = bd->finish + 1;
		}
		auto arg = new thr::cpu_data_t(bd, current_number_proc);

		/*Make distribution of threads between processors*/

		change_next_index_cpu(whole, remainder_np, current_number_proc,
							  save_current_number_for_proc, is_remainder_decreased);

#ifdef LOOK_AT_THE_CPU_DATA_TYPE
		std::cout << arg->bd_->start << " : " << arg->bd_->finish  << " " << arg->cpu_ << std::endl;
#endif

		//------------CREATE A THREAD AND CALL THE RUN FUNCTION TO CALCULATE MULTIPLICATION--------//

		ret = pthread_create(id(thr), NULL, run, arg);
		if (ret != 0)
			error_abort("error : pthread_create", ret);

	}

#ifdef DEBUG
	for(unsigned i = 0; i < threads; ++i){
		ret = pthread_join(ids[i], NULL);
		if(ret != 0)
			error_abort("error : pthread_join", ret);
	}
	thr::matrix<int> manual_res = left * right;

	if(manual_res == result){
		std::cerr << "OK!\n";
	}
	else {
		std::cerr << "NEOK!\n";
	}

	exit(EXIT_SUCCESS);
#endif

	pthread_exit(NULL);

}

void change_next_index_cpu(const unsigned &whole, unsigned &remainder_np, unsigned &current_number_proc,
						   int &save_current_number_for_proc, int &is_remainder_decreased)
{
	if (whole == 0)
		++current_number_proc;
	else {

		if (save_current_number_for_proc % whole == 0) {
			if (remainder_np && is_remainder_decreased == 0) {
				--remainder_np;
				is_remainder_decreased = 1;
			}
			else {
				++current_number_proc;
				is_remainder_decreased = 0;
				save_current_number_for_proc = 1;
			}

		}
		else ++save_current_number_for_proc;
	}
}

void *run(void *arg)
{
#ifndef DEBUG
	int ret = pthread_detach(pthread_self());
	if (ret != 0)
		error_abort("error : pthread_detach", ret);
#endif
	auto scope = reinterpret_cast<thr::cpu_data_t *>(arg);
	thr::distribute_relative_cpu(scope->cpu_);
	thr::parallel_matrix_multiplication(scope->bd_);

	delete scope->bd_;
	delete scope;

	return nullptr;
}

namespace thr
{
void distribute_relative_cpu(const unsigned cpu)
{
	cpu_set_t cpusetp;
	CPU_ZERO(&cpusetp);
	CPU_SET(cpu, &cpusetp);
	int ret = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpusetp);
	if (ret != 0)
		error_abort("pthread_setaffinity_np error", ret);
}

void parallel_matrix_multiplication(const bound_t *bd)
{
	assert(bd);

	int current_value = 0;
	int ret;

	for (unsigned row_l = bd->start; row_l <= bd->finish; ++row_l) {

		for (unsigned row_r = 0; row_r < n; ++row_r) {
			for (unsigned ip = 0; ip < n; ++ip) {
				current_value += left.arr_[row_l][ip] * right.arr_[row_r][ip];
			}
			ret = pthread_mutex_lock(&mtx);
			if (ret != 0)
				error_abort("error : pthread_mutex_lock", ret);

			result.arr_[row_l][row_r] = current_value;
			ret = pthread_mutex_unlock(&mtx);
			if (ret != 0)
				error_abort("error : pthread_mutex_unlock", ret);
			current_value = 0;
		}
	}

}
}