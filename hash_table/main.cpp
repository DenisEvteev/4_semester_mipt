#include "tests/hashTableTest.h"
#include "Hash_Table.h"
#include <fstream>
#include <csignal>
#include <cstdlib>

#define SEED 3802

CPPUNIT_TEST_SUITE_REGISTRATION(hashTableTest);

void sigfpe_handler(int sig);

/*The second argument of command line is optional
 * It represents the value for seeding the sequence for generating pseudo-random
 * integers via rand() function*/

int main(int argc, char **argv)
{

	if (argc > 2) {
		std::cerr << "Too big number of arguments" << std::endl;
		exit(EXIT_FAILURE);
	}

	struct sigaction act;
	act.sa_flags = 0;
	if (sigfillset(&act.sa_mask)) {
		std::cout << "error in sigfillset\n";
		std::abort();
	}
	act.sa_handler = sigfpe_handler;
	if (sigaction(SIGFPE, &act, NULL) == -1) {
		std::cerr << "error in sigaction\n";
		std::abort();
	}


	int seed{0};
	(argc == 2) ? seed = atoi(argv[1]) : seed = SEED;
	srand(seed);

	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	CppUnit::Test *suite = registry.makeTest();
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);
	runner.run();

	return 0;

}

void sigfpe_handler(int sig)
{
	std::cerr << "Arithmetical error was occured! "
				 "Try to write programs which don't divide by zero" << std::endl;
	std::abort();
}
