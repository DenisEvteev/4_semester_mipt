//
// Created by user on 23/03/2020.
//

#include "tests/testVecrot.h"


CPPUNIT_TEST_SUITE_REGISTRATION(testVecrot);

int main()
{
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	CppUnit::Test *suite = registry.makeTest();
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);
	runner.run();

	return 0;

}
