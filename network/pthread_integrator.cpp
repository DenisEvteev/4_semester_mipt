//
// Created by user on 22/05/2020.
//

#include "pthread_integrator.h"

double res;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
const double move = 0.0001;

void solve_problem(const bound_t& bound, double& result_per_machine){
	/*bound represent the general task to solve for this machine*/
	int threads = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
	std::cerr << "Number of available processors in machine : [ " << threads << " ]" <<  std::endl;
	double save_start = bound.start;
	unsigned current_number_proc = 0;
	double step = (bound.finish - bound.start) / static_cast<double>(threads);
	pthread_t* ids = new pthread_t[threads];

	int ret;
	for (int thr = 0; thr < threads; ++thr)
	{

		assert(current_number_proc <= threads - 1);
		bound_t* bd = nullptr;
		bd = new bound_t(save_start, (thr == threads - 1) ? bound.finish : save_start + step);
		save_start = bd->finish;
		auto arg = new cpu_data_t(bd, current_number_proc);

		++current_number_proc;

#ifdef LOOK_AT_THE_CPU_DATA_TYPE
		std::cout << arg->bd_->start << " : " << arg->bd_->finish  << " " << arg->cpu_ << std::endl;
#endif

		//------------CREATE A THREAD AND CALL THE RUN FUNCTION TO CALCULATE MULTIPLICATION--------//

		ret = pthread_create(&ids[thr], NULL, run, arg);
		if (ret != 0)
			error_abort(ret, "error : pthread_create");

	}


	for (int i = 0; i < threads; ++i)
	{
		ret = pthread_join(ids[i], NULL);
		if (ret != 0)
			error_abort(ret, "error : pthread_join");
	}

	result_per_machine = res;

	delete [] ids;


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
		error_abort(ret, "error : pthread_mutex_lock");

	res += thread_res;
	ret = pthread_mutex_unlock(&mtx);
	if (ret != 0)
		error_abort(ret, "error : pthread_mutex_unlock");

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
		error_abort(ret, "pthread_setaffinity_np error");
}

