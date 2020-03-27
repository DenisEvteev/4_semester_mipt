//
// Created by user on 15/03/2020.
//

#include "hashTableTest.h"


void hashTableTest::testConstructorThrow()
{
	Hash_Table<int> hashTable(38023802);
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(38023802), hashTable.size());
	//this test causes std::bad_alloc to be generated
	Hash_Table<int> ht(999999999999999);
	CPPUNIT_FAIL("std::bad_alloc wasn't generate --- the very strange condition has happened");

}

void hashTableTest::testZeroSize()
{
	Hash_Table<int> ht(0);
	CPPUNIT_FAIL("a very yucky thing has happened!!! The error in Constructor realization");
}

void hashTableTest::testInsertElement()
{
	Hash_Table<int> ht;
	std::size_t bucket = 0;
	Hash_Table<int>::Iterator it = ht.findEl(EDA_, bucket);
	CPPUNIT_ASSERT(ht.end() == it);
	CPPUNIT_ASSERT(!(ht.end() != it));
	CPPUNIT_ASSERT(ht.insert(static_cast<int>(EDA_)));
	it = ht.findEl(EDA_, bucket);
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(EDA_), *it);
	CPPUNIT_ASSERT(!ht.insert(static_cast<int>(EDA_)));
	CPPUNIT_ASSERT(ht.erase(EDA_));
	it = ht.findEl(EDA_, bucket);
	CPPUNIT_ASSERT(it == ht.end());
	CPPUNIT_ASSERT(!ht.erase(EDA_));
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
	for (int i = 0; i < 128; ++i) {
		auto pair = bucket_map.equal_range(i);
		if (pair.first == bucket_map.end())
			continue;
		for (auto it = pair.first; it != pair.second;) {
			if (((*it).second) == big_number - 1) {
				it = bucket_map.erase(it); // returns iterator to the next element after deleted
				continue;
			}
			CPPUNIT_ASSERT(ht.erase((*it).second));
			iterator = ht.findEl((*it).second, bucket);
			CPPUNIT_ASSERT(bucket == (*it).first);
			CPPUNIT_ASSERT(iterator == ht.end());
			it = bucket_map.erase(it);
		}
	}
	CPPUNIT_ASSERT(bucket_map.empty());
	//----------check the emptyness of the ht-------------------------//
	ht.showDistribution(bucket_map);
	CPPUNIT_ASSERT_EQUAL(static_cast<std::size_t>(0), bucket_map.size());
}

void hashTableTest::testCopyConstructorAssignmentOperator()
{
	//----------------------difficult test---------------------------//
	//create Hash_Table filling it with [random values]
	Hash_Table<int> ht(500);
	CPPUNIT_ASSERT(&(ht = ht) == &ht); // check the case of self assignment
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, 2000);
	bool if_inserted = ht.insert(15);
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
	std::size_t bucket = 0;
	Hash_Table<int>::Iterator it = ht.findEl(3802, bucket);
	CPPUNIT_ASSERT(it != ht.end());
	CPPUNIT_ASSERT(*it == 3802);
	if (if_inserted) {
		it = ht.findEl(15, bucket);
		CPPUNIT_ASSERT(it == ht.end());
	}

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
		if (ht.insert(std::rand()))
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
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, 20000);
	DUMP_IN_FILE("tests/big_hash_table", logFile1, ht);
	//------------------check dumping hash_table with empty buckets------------------//
	ht = Hash_Table<int>(); // to say the truth move assignment operator will work here
	CPPUNIT_ASSERT(ht.size() == 128);
	_FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, 50);
	DUMP_IN_FILE("tests/small_hash_table", logFile2, ht);
}

void hashTableTest::testEasyCoverage()
{
	Hash_Table<int> ht;
	auto it = ht.begin();
	try {
		CPPUNIT_ASSERT(!ht[0]);
		*it = 1;
		CPPUNIT_FAIL("operator*() hasn't thrown an exception --- is a very strange situation");
	}
	catch (const std::runtime_error &el) {}
	it--;
	CPPUNIT_ASSERT(it == ht.begin());
	--it;
	CPPUNIT_ASSERT(it == ht.begin());

	it = ht.end();
	it++;
	CPPUNIT_ASSERT(it == ht.end());
	++it;
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
	try {
		if (ht2[3000])
			CPPUNIT_FAIL("Error!!! You cannot have access to this memory");
	}catch(const std::out_of_range&){}
}

void hashTableTest::testMoveAssignmentOperator()
{
	Hash_Table<int>
		ht = Hash_Table<int>(512); //  [just for fun] My Hash_Table is clever so I can write strings like this one
	CPPUNIT_ASSERT(&(ht = std::move(ht)) == &ht);  // check the case of self assignment in move constructor
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

void hashTableTest::testExceptionCaseAssignmentOperator()
{
	/*I'd like to check the state of Hash_Table object at the case
	when while copying the object an exception can arise in which case
	my program should remain the object at the initial state --- strict guarantee relative exception*/
	using map_yucky = std::multimap<std::size_t, Yucky>;
	Hash_Table<Yucky> hard;
	for (int i = 0; i < 2000; ++i) {
		hard.insert(Yucky(std::rand()));
	}

	CPPUNIT_ASSERT(&(hard = hard) == &hard); // check the case of self assignment
	map_yucky initial;
	hard.showDistribution(initial);
	CPPUNIT_ASSERT(!initial.empty());

	Hash_Table<Yucky> rhs;
	for (int i = 0; i < 5000; ++i) {
		CPPUNIT_ASSERT(rhs.insert(Yucky(i))); // at runtime we have an error which says that we call copy constructor at this point
	}

	try {
		/*But obviously we have some likehood that we won't be able to generate an exception
		  at the right place so We won't have code coverage as we wanted*/
		hard = rhs; // we want to see the hard at the exact initial state after an exception has been raised
		CPPUNIT_FAIL("change condition for generation an exception from copy ctor");
	}
	catch (const std::exception &exc) {
		CPPUNIT_ASSERT(hard.size() == 128); // as it was at the initial case
		map_yucky later;
		hard.showDistribution(later);
		CPPUNIT_ASSERT(later == initial);
	}
}

void hashTableTest::testExceptionCaseCopyConstructor()
{
	Hash_Table<Yucky> rhs;
	CPPUNIT_ASSERT(rhs.size() == 128);
	for (int i = 0; i < 5000; ++i) {
		CPPUNIT_ASSERT(rhs.insert(Yucky(i))); // at runtime we have an error which says that we call copy constructor at this point
	}
	/*This action mustn't generate any type of memory leak or pointers corruptions*/
	Hash_Table<Yucky> copy_rhs = rhs;
	CPPUNIT_FAIL("copy constructor hasn't thrown an exception --- a very bad case!!!");

}

void hashTableTest::setUp()
{}
void hashTableTest::tearDown()
{}