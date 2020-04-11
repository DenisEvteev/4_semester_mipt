//
// Created by user on 23/03/2020.
//

#include "testVector.h"

using namespace my_push_back;

Yucky::Yucky(int a)
	: a_(a)
{
	ar_ = new int[a_];
}

Yucky::~Yucky()
{
	delete[] ar_;
}

Yucky::Yucky(const Yucky &el)
	: a_(el.a_)
{
	if (a_ >= _SIZE)
		throw std::runtime_error("overflow size of arr_ in Yucky object to copy");
	ar_ = new int[a_];
}

Yucky::Yucky(Yucky &&el) noexcept
	: ar_(el.ar_), a_(el.a_)
{
	el.ar_ = nullptr;
	el.a_ = 0;
}

void testVector::setUp()
{}
void testVector::tearDown()
{}

void testVector::testPushLvalue()
{
	vector<int, TrackingAllocator<int>> simple;
	CPPUNIT_ASSERT(static_cast<std::size_t>(DEFAULT_SIZE) == simple.capasity());


	for (int i = 0; i < 100; ++i) {
		simple.push_back(i);
		CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(i + 1), simple.size());
	}
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(160), simple.capasity());
	simple.push_back(simple[99]);
	CPPUNIT_ASSERT(simple[100] == simple[99]);
	/*Check the case when constructor of object which resides in the vector array
	 * can throw an array -- the most interesting thing in here is*/

	vector<Yucky, TrackingAllocator<Yucky>> excep;
	int i = 0;
	try {
		for (; i < 1000; ++i) {
			Yucky yep(i);
			excep.push_back(yep);
			CPPUNIT_ASSERT(excep[i].a_ == i);
		}
		CPPUNIT_FAIL("the exception wasn't thrown --- bad error !!!");
	}
	catch (const std::runtime_error &exc) {
		CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(DEFAULT_SIZE), excep.capasity());
		CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(DEFAULT_SIZE), excep.size());
		//Check pushing_back a copy of an object situated in excep
		excep.push_back(excep[5]);
		CPPUNIT_ASSERT(DEFAULT_SIZE * 2 == excep.capasity());
		CPPUNIT_ASSERT(DEFAULT_SIZE + 1 == excep.size());
		CPPUNIT_ASSERT(excep[5].a_ == excep[10].a_);
	}
}

void testVector::testPushRvalue()
{
	vector<int, TrackingAllocator<int>> simple;
	for (int i = 0; i < 21; ++i) {
		simple.push_back(std::move(i));
		CPPUNIT_ASSERT(simple.size() == static_cast<std::size_t>(i + 1));
	}
	CPPUNIT_ASSERT(simple.capasity() == 40);
	simple.push_back(std::move(simple[0]));
	CPPUNIT_ASSERT(simple.size() == 22);
	CPPUNIT_ASSERT(simple[0] == simple[21]);

	vector<Yucky, TrackingAllocator<Yucky>> hard;
	for (int i = 0; i < 100; ++i) {
		hard.push_back(Yucky(i));
		CPPUNIT_ASSERT(hard.size() == static_cast<std::size_t>(i + 1));
		CPPUNIT_ASSERT(hard[i].a_ == i);
	}

	CPPUNIT_ASSERT(hard.capasity() == 160);
}