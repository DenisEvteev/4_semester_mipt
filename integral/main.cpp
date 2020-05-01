#include "error.h"

const double start = 2;
const double finish = 70002;
const double move = 0.0001;

#define MAX_COUNT_THREADS 100000

#define func(x) ( 1 / std::log( x ) )

double res;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void change_next_index_cpu(const unsigned& whole, unsigned& remainder_np, unsigned& current_number_proc,
	int& save_current_number_for_proc, int& is_remainder_decreased);
void* run(void* arg);
void distribute_relative_cpu(const unsigned cpu);
void* stupid_routine(void* arg);

int main(int argc, char** argv)
{

	if (argc != 2)
	{
		std::cerr << "error : bad amount of arguments!\n";
		exit(EXIT_FAILURE);
	}
	unsigned threads = std::atoi(argv[1]);
	assert(threads != 0);
	if (threads > MAX_COUNT_THREADS)
	{
		std::cerr << "error : too big number of threads\n";
		exit(EXIT_FAILURE);
	}

	unsigned processors = sysconf(_SC_NPROCESSORS_CONF);
	double save_start = start;
	unsigned current_number_proc = 0;

	double step = (finish - start)
				  / static_cast<double>(threads); // This variable of type double, so I shouldn't cope with the possible excess varialbe
	//some local variables for per cpu distribution
	unsigned remainder_np = threads % processors, whole = threads / processors;
	int is_remainder_decreased = 0, save_current_number_for_proc = 1;

	pthread_t* ids = new pthread_t[threads];

	int ret;
	for (unsigned thr = 0; thr < threads; ++thr)
	{

		bound_t* bd = nullptr;
		bd = new bound_t(save_start, (thr == threads - 1) ? finish : save_start + step);
		save_start = bd->finish;
		auto arg = new cpu_data_t(bd, current_number_proc);

		/*Make distribution of threads between processors*/

		change_next_index_cpu(whole, remainder_np, current_number_proc,
			save_current_number_for_proc, is_remainder_decreased);

#ifdef LOOK_AT_THE_CPU_DATA_TYPE
		std::cout << arg->bd_->start << " : " << arg->bd_->finish  << " " << arg->cpu_ << std::endl;
#endif

		//------------CREATE A THREAD AND CALL THE RUN FUNCTION TO CALCULATE MULTIPLICATION--------//

		ret = pthread_create(&ids[thr], NULL, run, arg);
		if (ret != 0)
			error_abort("error : pthread_create", ret);

	}

	unsigned stupid_routines = 0;
	if (threads < processors)
		stupid_routines = processors - threads;
	unsigned cur = 0;
	pthread_t tid;
	while (cur < stupid_routines)
	{
		unsigned* cp_ptr = new unsigned;
		*cp_ptr = threads + cur;
		ret = pthread_create(&tid, NULL, stupid_routine, cp_ptr);
		if (ret != 0)
			error_abort("error : pthread_create", ret);
		++cur;
	}

	for (unsigned i = 0; i < threads; ++i)
	{
		ret = pthread_join(ids[i], NULL);
		if (ret != 0)
			error_abort("error : pthread_join", ret);
	}

	std::cout << res << std::endl;
	delete[] ids;
	return 0;

}

void* stupid_routine(void* arg)
{
	/*-------I should force this thread to execute at the special logic processor-----*/
	unsigned* cp_ptr = reinterpret_cast<unsigned*>(arg);
	distribute_relative_cpu(*cp_ptr);
	delete cp_ptr;
	//-------------------------------------------------------------------------------//
	while (1)
	{ /*Just make each core to work with the frequency seeking to the Turbo Boost limit*/}
}

void* run(void* arg)
{
	auto scope = reinterpret_cast<cpu_data_t*>(arg);
	distribute_relative_cpu(scope->cpu_);
	//--------------PERFORM ACTIONS------------------//
	double thread_res = 0;
	double go_ = scope->bd_->start;

	while (go_ < scope->bd_->finish)
	{
		thread_res += (func(go_) * move);
		go_ += move;
	}

	int ret;
	ret = pthread_mutex_lock(&mtx);
	if (ret != 0)
		error_abort("error : pthread_mutex_lock", ret);

	res += thread_res;
	ret = pthread_mutex_unlock(&mtx);
	if (ret != 0)
		error_abort("error : pthread_mutex_unlock", ret);

	delete scope->bd_;
	delete scope;

	return nullptr;
}

void distribute_relative_cpu(const unsigned cpu)
{
	cpu_set_t cpusetp;
	CPU_ZERO(&cpusetp);
	CPU_SET(cpu, &cpusetp);
	int ret = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpusetp);
	if (ret != 0)
		error_abort("pthread_setaffinity_np error", ret);
}

void change_next_index_cpu(const unsigned& whole, unsigned& remainder_np, unsigned& current_number_proc,
	int& save_current_number_for_proc, int& is_remainder_decreased)
{
	if (whole == 0)
		++current_number_proc;
	else
	{

		if (save_current_number_for_proc % whole == 0)
		{
			if (remainder_np && is_remainder_decreased == 0)
			{
				--remainder_np;
				is_remainder_decreased = 1;
			}
			else
			{
				++current_number_proc;
				is_remainder_decreased = 0;
				save_current_number_for_proc = 1;
			}

		}
		else ++save_current_number_for_proc;
	}
}