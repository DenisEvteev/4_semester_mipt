#include "matrix.h"

/*This moment the design of the program is simplified to multiplication just quadratic matrices
 TODO : to add support to multiply matrices of arbitary size (only one usual restriction) */

thr::matrix<int> left, right, result;

const unsigned n = 1500;

const unsigned m = 1500;

///*This global integer is used for synchronize between all the threads
//// * to start perform multiplication of two matrices*/
static int number_threads;
//
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER; //predicate for this conditional variable is [number_threads == 0]
//pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


/* I add 1 to the result to find out the situations when two threads didn't
 * perform with filling a matrix with the right values */

#define RAND_NUMBER ( std::rand() % 10 + 1 )

thr::bound_t *prepare_bounds_for_arg(unsigned &save_row_s, unsigned &save_col_s, unsigned sz);
void init_input_matrices();
void *run(void *arg);
void *fill(void *arg);
void fill_matrix_with_random_values(thr::bound_t *scope, thr::matrix<int> &matrix);
void multiplicate_part_matrices(thr::bound_t *scope);
void make_bounds(std::vector<thr::cpu_data_t *> &data);
//void transpose_multiplicate_part_matrices(thr::bound_t  * scope);
void make_environment(int cpu);

int main(int argc, char **argv)
{

	if (argc != 2) {
		std::cerr << "bad amount of arguments!" << std::endl;
		exit(EXIT_FAILURE);
	}

	try {
		init_input_matrices();
	}
	catch (const std::bad_alloc &ex) {
		std::cerr << ex.what() << std::endl;
		std::cerr << "The process will be finished abnormally due to the free memory expiring" << std::endl;
		exit(EXIT_FAILURE);
	}


	int threads = std::atoi(argv[1]);
	assert(threads > 0);
	number_threads = threads; // init the global variable for synchronization
	if (threads > static_cast<int>(n * n)) {
		std::cerr << "a very big number of threads" << std::endl;
		exit(EXIT_FAILURE);
	}

	//-------------MAKE PREPARATION BOUNDS FOR MATRICES---------------//
	std::vector<thr::cpu_data_t *> data;
	make_bounds(data);
	//----------------------------------------------------------------//

	//------FILL MATRICES WITH RANDOM VALUES IN PARALLEL-------//
	int ret = 0;
	std::vector<pthread_t> ids(threads);
	for (int thr = 0; thr < threads; ++thr) {

		ret = pthread_create(&ids[thr], NULL, fill, data[thr]);
		if (ret != 0)
			error_abort("pthread_create error", ret);

	}
	for (int i = 0; i < threads; ++i) {
		ret = pthread_join(ids[i], NULL);
		if (ret != 0)
			error_abort("pthread_join", ret);
	}

//	//-------------------------------------------------------//
//	thr::matrix<int> copy_right = right;
//	right.parallel_transpose_matrix();

	//------------------MULTIPLICATION-----------------------//
	for (int thr = 0; thr < threads; ++thr) {
		ret = pthread_create(&ids[thr], NULL, run, data[thr]);
		if (ret != 0)
			error_abort("pthread_create error", ret);

	}
	for (int i = 0; i < threads; ++i) {
		ret = pthread_join(ids[i], NULL);
		if (ret != 0)
			error_abort("pthread_join", ret);
	}
	//-------------------------------------//
	for (auto el : data) {
		delete el->bd_;
		delete el;
	}


#ifdef DEBUG
	thr::matrix<int> manual_res = left * right;
	if(result == manual_res){
		std::cout << "OK" << std::endl;
	}
	else {
//		std::cout << result << std::endl;
//		std::cout << manual_res << std::endl;
	}
#endif

	return 0;
}

void make_bounds(std::vector<thr::cpu_data_t *> &data)
{
	int processors = static_cast<int>(sysconf(_SC_NPROCESSORS_CONF));
	assert(processors > 0);
	int remainder_np = processors % number_threads;
	unsigned save_row_s = 0, save_col_s = 0;
	unsigned max = left.get_lines() * left.get_lines();
	unsigned sz;
	int current_number_proc = 0;
	for (int thr = 0; thr < number_threads; ++thr) {
		sz = max / static_cast<unsigned>( number_threads - thr );
		thr::bound_t *bound;
		if (thr != number_threads - 1)
			bound = prepare_bounds_for_arg(save_row_s, save_col_s, sz);
		else {
			bound = new thr::bound_t;
			bound->col_s = save_col_s;
			bound->col_f = n - 1;
			bound->row_s = save_row_s;
			bound->row_f = n - 1;
		}
		/*Here I should think about how to produce the right number of processor to execute on*/
		if (remainder_np < 0) {
			++current_number_proc;
			current_number_proc %= processors;
		}

		auto arg = new thr::cpu_data_t(bound, current_number_proc);
		max -= sz;
		--remainder_np;
		data.push_back(arg);
	}
}

thr::bound_t *prepare_bounds_for_arg(unsigned &save_row_s, unsigned &save_col_s, unsigned sz)
{
	unsigned how_many_whole, remainder, available_delta;

	auto arg = new thr::bound_t;
	arg->col_s = save_col_s;
	arg->row_s = save_row_s;
	how_many_whole = sz / left.get_lines();
	available_delta = left.get_lines() - arg->col_s;
	if (how_many_whole < 1) {
		if (available_delta >= sz) {
			arg->col_f += save_col_s + sz - 1;
			arg->row_f = save_row_s;
		}
		else {
			arg->col_f = sz - available_delta - 1;
			arg->row_f += save_row_s + 1;
		}
	}
	else {
		sz -= available_delta;
		remainder = sz % left.get_lines();
		arg->col_f = (remainder) ? (remainder - 1) : (left.get_lines() - 1);
		arg->row_f += (save_row_s == left.get_lines() - 1) ? (save_row_s) :
					  (save_row_s + how_many_whole);
		if (!remainder && available_delta == left.get_lines()) // I should catch the case when I should low the row of
			--arg->row_f;
	}
#ifdef DEBUG
	assert(arg->row_f <= left.get_lines() - 1);
	assert(arg->col_f <= left.get_lines() - 1);
#endif
	if (arg->col_f == left.get_lines() - 1) {
		save_col_s = 0;
		save_row_s = arg->row_f + 1;
	}
	else {
		save_col_s = arg->col_f + 1;
		save_row_s = arg->row_f;
	}
	return arg;
}

void init_input_matrices()
{
	left.make_arr(n, m);
	right.make_arr(m, n);
	result.make_arr(n, m);

}

void *fill(void *arg)
{
	auto scope = reinterpret_cast<thr::cpu_data_t *>(arg);
	/*-----Make preparation to run a thread in a very good isolation-----*/
	make_environment(scope->cpu_);
	//-------------------------------------------------------------------//
	fill_matrix_with_random_values(scope->bd_, left);
	fill_matrix_with_random_values(scope->bd_, right);

	return nullptr;
}

void *run(void *arg)
{
	auto scope = reinterpret_cast<thr::cpu_data_t *>(arg);
	/*-----Make preparation to run a thread in a very good isolation-----*/
	make_environment(scope->cpu_);
	//----------Every fairy tale comes to an end-----------------//

//	transpose_multiplicate_part_matrices(scope->bd_);
	multiplicate_part_matrices(scope->bd_);

	return nullptr;

}

void make_environment(int cpu)
{
	assert(cpu >= 0);
	cpu_set_t cpusetp;
	CPU_ZERO(&cpusetp);
	CPU_SET(cpu, &cpusetp);
	int ret = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpusetp);
	if (ret != 0)
		error_abort("pthread_setaffinity_np error", ret);

}

void fill_matrix_with_random_values(thr::bound_t *scope, thr::matrix<int> &matrix)
{
	assert(scope);
	unsigned col_up_bound, col_down_bound;

	for (unsigned row = scope->row_s; row <= scope->row_f; ++row) {
		(row == scope->row_f) ? (col_up_bound = scope->col_f) : (col_up_bound = left.get_lines() - 1);
		(row == scope->row_s) ? (col_down_bound = scope->col_s) : (col_down_bound = 0);
		for (unsigned col = col_down_bound; col <= col_up_bound; ++col) {
			matrix.set_arr(row, col, RAND_NUMBER);
		}
	}
}

/*It's a common algorithm of multiplication of two matrices
 * The usual way to do it but with data for input it fails with a very bad result*/
void multiplicate_part_matrices(thr::bound_t *scope)
{
	assert(scope);
	unsigned col_up_bound, col_down_bound;
	int current_value = 0;

	for (unsigned row = scope->row_s; row <= scope->row_f; ++row) {
		(row == scope->row_f) ? (col_up_bound = scope->col_f) : (col_up_bound = left.get_lines() - 1);
		(row == scope->row_s) ? (col_down_bound = scope->col_s) : (col_down_bound = 0);
		for (unsigned col = col_down_bound; col <= col_up_bound; ++col) {
			for (unsigned ip = 0; ip < n; ++ip) {
				current_value += left.get_arr(row, ip) * right.get_arr(ip, col);
			}
			result.set_arr(row, col, current_value);
			current_value = 0;
		}
	}

}