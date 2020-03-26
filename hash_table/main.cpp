#include "tests/hashTableTest.h"


#define SEED 3802

CPPUNIT_TEST_SUITE_REGISTRATION(hashTableTest);

/*The second argument of command line is optional
 * It represents the value for seeding the sequence for generating pseudo-random
 * integers via rand() function*/

int main(int argc, char **argv)
{
	if (argc > 2) {
		std::cerr << "Too big number of arguments" << std::endl;
		exit(EXIT_FAILURE);
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
