//
// Created by user on 15/03/2020.
//

#include "hashTableTest.h"


void hashTableTest::testConstructorThrow()
{
	Hash_Table<int> hashTable(38023802);
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(38023802), hashTable.size());
	try {
		Hash_Table<int> ht(999999999999999);
	}
	catch (const std::bad_alloc &el) {}

}

void hashTableTest::testRedefineAllocOpers()
{
	auto simple_cover_one_constructor = new Hash_Table<int>();
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(128), simple_cover_one_constructor->size());
	/*The line below will cause an exception of type std::runtime_error*/
	try {
		auto hashTable = new Hash_Table<int>(38023802);
		/*compilator will implicitly call the redefine operator delete in this case
		 * As I have implemented it and we didn't manage to contruct the whole object and
		 * return pointer to it*/
	}
	catch (...) {
		delete simple_cover_one_constructor;
	}

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
	Hash_Table<int> ht(500);
	for (int i = 0; i < 2000; ++i) {
		ht.insert(rand());
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

void hashTableTest::testIncrementDecrementOperators()
{
	std::size_t number_insertions{0};
	Hash_Table<int> ht(512);
	for (int i = 0; i < 5000; ++i) {
		if (ht.insert(rand()))
			++number_insertions;
	}
	map save_state;
	ht.showDistribution(save_state);
	Hash_Table<int>::Iterator it = ht.begin();
	Hash_Table<int>::Iterator end = ht.end();
	std::size_t count = 0;
	for (; it != end; it++) {
		++count;
	}
	CPPUNIT_ASSERT_EQUAL(number_insertions, count);
	CPPUNIT_ASSERT(it == ht.end());
	map check_ht_after_traversing;
	ht.showDistribution(check_ht_after_traversing);
	CPPUNIT_ASSERT(save_state == check_ht_after_traversing);
	//----------------------prefix decrement---------------------------//
	for (; it != ht.begin(); --it) {
		count--;
	}
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(0), count);
	CPPUNIT_ASSERT(it == ht.begin());
	//----------------------postfix decrement--------------------------//
	it = ht.end();
	count = 0;
	for (; !(it == ht.begin()); it--) {
		count++;
	}
	CPPUNIT_ASSERT_EQUAL(number_insertions, count);
	CPPUNIT_ASSERT(it == ht.begin());
	//-----------------------check invariant of this hash_table---------------------//
	ht.showDistribution(check_ht_after_traversing);
	CPPUNIT_ASSERT(save_state == check_ht_after_traversing);
}

void hashTableTest::testOperatorDumpingIntoFile()
{
	Hash_Table<int> ht(3802);
	for (int i = 0; i < 10000; ++i) {
		ht.insert(rand());
	}
	DUMP_IN_FILE("big_hash_table", logFile1, ht);
	//------------------check dumping hash_table with empty buckets------------------//
	ht = Hash_Table<int>();
	for (int i = 0; i < 35; ++i) {
		ht.insert(rand());
	}
	DUMP_IN_FILE("small_hash_table", logFile2, ht);
}

void hashTableTest::testEasyCoverage()
{
	Hash_Table<int> ht;
	auto it = ht.begin();
	it--;
	CPPUNIT_ASSERT(it == ht.begin());
	//--------check postfix increment----------------//
	it = ht.end();
	it++;
	CPPUNIT_ASSERT(it == ht.end());
	//---------check operator [] in class Hash_Table--------//
	for (int i = 0; i < 128; ++i) {
		CPPUNIT_ASSERT(!ht[0]);
	}
}

void hashTableTest::setUp()
{}
void hashTableTest::tearDown()
{}