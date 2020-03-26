//
// Created by user on 23/03/2020.
//

#ifndef TESTVECROT_H
#define TESTVECROT_H

#include "../vecrot.h"
#include "../TrackingAllocator.h"
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>


#define _SIZE 10

/*I specially have written move constructor noexcept as I have already notice
 * I don't know yet how to understand whether move constructor is noexcept or no --- this is the pivotal question when
 * implement push_back with rvalue reference */
struct Yucky
{
	explicit Yucky(int a);
	Yucky(const Yucky &el); // copy constructor throw an exception at the case when the field a_ is equal to 100
	Yucky(Yucky &&el) noexcept;
	~Yucky();
	Yucky &operator=(const Yucky &el) = delete;
	Yucky &operator=(Yucky &&el) = delete;
	int *ar_ = nullptr;
	int a_ = _SIZE;
};

class testVecrot: public CppUnit::TestFixture
{
public :

	void testPushLvalue();
	void testPushRvalue();


CPPUNIT_TEST_SUITE(testVecrot);
		CPPUNIT_TEST(testPushLvalue);
		CPPUNIT_TEST(testPushRvalue);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

};


#endif //TESTVECROT_H
