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
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, 2000);
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
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, 10000);
	DUMP_IN_FILE("big_hash_table", logFile1, ht);
	//------------------check dumping hash_table with empty buckets------------------//
	ht = Hash_Table<int>(); // to say the truth move assignment operator will work here
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, 35);
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

void hashTableTest::testMoveConstructor()
{
	Hash_Table<int> ht;
	map initial_map;
	/*check function showDistribution for returning empty map
	 * in case when all the cells in hash_table are just raw */
	ht.showDistribution(initial_map);
	CPPUNIT_ASSERT(initial_map.empty());
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, 1128);
	ht.showDistribution(initial_map);
	Hash_Table<int> move_copy = std::move(ht);
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(128), move_copy.size());
	map move_map;
	move_copy.showDistribution(move_map);
	CPPUNIT_ASSERT(move_map == initial_map);
	//------------------------------------------------------------------------------//
	//another interesting way to check the work of the move constructor
	Hash_Table<int> ht2 = Hash_Table<int>(2000);  //move constructor will work in this case
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(2000), ht2.size());
	for(int i = 0; i < 2000; ++i)
	{
		CPPUNIT_ASSERT(!ht2[i]);
	}
	//I want check the case when operator [] throw an exception
	// in case when we require an index over the bound of avaliable
	try{
		if(ht2[3000])
			std::cout << "a very big fail on the " << __LINE__ << std::endl;
	}catch(const std::out_of_range&){}
}

void hashTableTest::testMoveAssignmentOperator()
{
	Hash_Table<int> ht = Hash_Table<int>(512); //  [just for fun] My Hash_Table is clever so I can write strings like this one
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, 5000);
	map map_ht;
	ht.showDistribution(map_ht);
	Hash_Table<int> ht1;
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht1, 10000);

	ht1 = std::move(ht);
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(512), ht1.size());
	map current_map_ht1;
	ht1.showDistribution(current_map_ht1);
	CPPUNIT_ASSERT(current_map_ht1 == map_ht);
}

void hashTableTest::setUp()
{}
void hashTableTest::tearDown()
{}