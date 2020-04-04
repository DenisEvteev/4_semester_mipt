//
// Created by user on 03/04/2020.
//

#define USE_CPPUNIT_TEST the_way_to_SP

#ifdef USE_CPPUNIT_TEST
#include "tests/testSolution.h"
CPPUNIT_TEST_SUITE_REGISTRATION(testSolution);

#else
#include "Solution.h"
#endif


int main()
{

#ifdef USE_CPPUNIT_TEST
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	CppUnit::Test *suite = registry.makeTest();
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);
	runner.run();
#else

	dot::Solution sl1;
	std::cin >> sl1;
	std::cout << sl1.find_nearest_dist();

#endif

	return 0;

}