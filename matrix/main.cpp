#include "matrix.h"

/*This moment the design of the program is simplified to multiplication just quadratic matrices*/

thr::matrix<int> left, right, result; //global matrices
const unsigned n = 1000;

const unsigned m = 1000;

/*This global integer is used for synchronize between all the threads
 * to start perform multiplication of two matrices*/
static int number_threads;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER; //predicate for this conditional variable is [number_threads == 0]
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

using bound_t = struct thr::bound;

/* I add 1 to the result to find out the situations when two threads didn't
 * perform with filling a matrix with the right values */

#define RAND_NUMBER ( std::rand() % 10 + 1 )

bound_t *prepare_bounds_for_arg(unsigned &save_row_s, unsigned &save_col_s, unsigned sz);
void init_input_matrices();
void *run(void *arg);
void fill_matrix_with_random_values(bound_t *scope, thr::matrix<int> &matrix);
void multiplicate_part_matrices(bound_t *scope);

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

	int count_threads = std::atoi(argv[1]);
	assert(count_threads > 0);
	number_threads = count_threads; // init the global variable for synchronization

	std::vector<pthread_t> ids(count_threads);
	unsigned save_row_s = 0;
	unsigned save_col_s = 0;
	unsigned max = left.get_lines() * left.get_lines();
	unsigned sz;

	for (int thr = 0; thr < count_threads; ++thr) {
		sz = max / static_cast<unsigned>( count_threads - thr );
		auto arg = prepare_bounds_for_arg(save_row_s, save_col_s, sz);
		max -= sz;

		if (pthread_create(&ids[thr], NULL, run, arg) != 0)
			error_abort("pthread_create error");

	}


	for (int ip = 0; ip < count_threads; ++ip) {
		if (pthread_join(ids[ip], NULL) != 0)
			error_abort("pthread_join error");
	}


#ifdef DEBUG
	std::cout << left << std::endl;
	std::cout << right << std::endl;
	thr::matrix<int> manual_res = left * right;
	std::cout << manual_res << std::endl;
	std::cout << result << std::endl;
	assert(manual_res == result);
#endif

	return 0;
}

bound_t *prepare_bounds_for_arg(unsigned &save_row_s, unsigned &save_col_s, unsigned sz)
{
	unsigned how_many_whole, remainder, available_delta;

	auto arg = new bound_t;
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

void *run(void *arg)
{
	auto scope = reinterpret_cast<bound_t *>(arg);

	fill_matrix_with_random_values(scope, left);
	fill_matrix_with_random_values(scope, right);

	//---------SYNCHRONIZE THREADS------------------//
	if (pthread_mutex_lock(&mtx) != 0)
		error_abort("pthread_mutex_lock error");

	--number_threads;

	if (!number_threads) // the case when the last pthread came to the critical section
	{
		if (pthread_cond_broadcast(&cond) != 0)
			error_abort("pthread_cond_broadcast error");
	}
	while (number_threads) {
		if (pthread_cond_wait(&cond, &mtx) != 0)
			error_abort("pthread_cond_wait error");
	}

	if (pthread_mutex_unlock(&mtx) != 0)
		error_abort("pthread_mutex_unlock error");

	//---------------------------------------------//
	multiplicate_part_matrices(scope);


	delete scope;
	return nullptr;
}

void fill_matrix_with_random_values(bound_t *scope, thr::matrix<int> &matrix)
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

void multiplicate_part_matrices(bound_t *scope)
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