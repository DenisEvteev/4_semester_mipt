//
// Created by user on 15/03/2020.
//

#include "hashTableTest.h"


void hashTableTest::testConstructorThrow()
{
	Hash_Table<int> hashTable(38023802);
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(38023802), hashTable.size());
	Hash_Table<int>(999999999999999);

}

void hashTableTest::testRedefineAllocOpers()
{
	auto simple_cover_one_constructor = new Hash_Table<int>;
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(128), simple_cover_one_constructor->size());
	/*The line below will cause an exception of type std::runtime_error*/

//	try{
	auto hashTable = new Hash_Table<int>(38023802);
//		/*compilator will implicitly call the redefine operator delete in this case
//		 * As I have implemented it and we didn't manage to contruct the whole object and
//		 * return pointer to it*/
//	}catch(const std::runtime_error& er){
//		delete simple_cover_one_constructor;
//	}

}

void hashTableTest::testInsertElement()
{
	Hash_Table<int> ht;
	std::size_t bucket = 0;
	Hash_Table<int>::Iterator it = ht.findEl(EDA_, bucket);
	CPPUNIT_ASSERT(ht.end() == it);
	CPPUNIT_ASSERT(!(ht.end() != it));
	CPPUNIT_ASSERT(ht.insert(EDA_));
	it = ht.findEl(EDA_, bucket);
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(EDA_), *it);
	CPPUNIT_ASSERT(!ht.insert(EDA_));
}

void hashTableTest::testInsertBigAmountAndErase()
{
	Hash_Table<int> ht(128);
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(128), ht.size());
	int big_number = _BIG_NUMBER;
	std::size_t bucket = 0;
	/*This multimap contains different bucket number and all the elements which belong this bucket
	 * I'm going to use this multimap for testing find and erase algorithms in further actions*/
	std::multimap<std::size_t, int> bucket_map;
	for (int i = 0; i < big_number; ++i) {
		CPPUNIT_ASSERT(ht.insert(i));
		Hash_Table<int>::Iterator it = ht.findEl(i, bucket);
		CPPUNIT_ASSERT(*it == i);
		bucket_map.insert(std::make_pair(bucket, *it));
	}
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(_BIG_NUMBER), bucket_map.size());
	//-----------------erase ------------------------------//
	CPPUNIT_ASSERT(ht.erase(big_number - 1));
	Hash_Table<int>::Iterator it = ht.findEl(big_number - 1, bucket);
	CPPUNIT_ASSERT(it == ht.end());
	CPPUNIT_ASSERT(!ht.erase(big_number - 1));
	//-----------------erase the whole table by elements -----------------//
	Hash_Table<int>::Iterator iterator;
	for (int i = 0; i < ht.size(); ++i) {
		auto pair = bucket_map.equal_range(i);
		if (pair.first == bucket_map.end())
			continue;
		for (auto it = pair.first; it != pair.second; ++it) {
			if (((*it).second) == big_number - 1)
				continue;
			CPPUNIT_ASSERT(ht.erase((*it).second));
			iterator = ht.findEl((*it).second, bucket);
			CPPUNIT_ASSERT(iterator == ht.end());
		}
	}
	//----------check the emptyness of the ht-------------------------//
	ht.showDistribution(bucket_map);
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(0), bucket_map.size());
}

void hashTableTest::testCopyConstructorAssignmentOperator()
{
	//----------------------difficult test---------------------------//
	//create Hash_Table filling it with [random values]
	Hash_Table<int> ht(static_cast<std::size_t>(4000));
	for (int i = 0; i < 1000; ++i) {
		CPPUNIT_ASSERT(ht.insert(rand()));
	}
	Hash_Table<int> copy = ht;                                      //copy constructor
	CPPUNIT_ASSERT_EQUAL(ht.size(), copy.size());
	map initial, second;
	ht.showDistribution(initial);
	copy.showDistribution(second);
	CPPUNIT_ASSERT(initial == second);
	//------------------------------------------------------//
	Hash_Table<int> empty_ht;
	CPPUNIT_ASSERT(empty_ht.insert(3802));
	ht = empty_ht;                                               //assignment operator
	CPPUNIT_ASSERT_EQUAL(empty_ht.size(), ht.size());
	ht.showDistribution(initial);
	empty_ht.showDistribution(second);
	CPPUNIT_ASSERT(second == initial);
	//once more check
	empty_ht = copy;                                            //assignemt operator
	CPPUNIT_ASSERT_EQUAL(copy.size(), empty_ht.size());
	empty_ht.showDistribution(initial);
	copy.showDistribution(second);
	CPPUNIT_ASSERT(second == initial);
}

void hashTableTest::setUp()
{}
void hashTableTest::tearDown()
{}