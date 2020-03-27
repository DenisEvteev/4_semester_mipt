//
// Created by user on 28/02/2020.
//

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

#include <new>
#include <iostream>
#include <stack>
#include <map>
#include <fstream>

//#define C_PLUS_PLUS_IS_ALLOWED 3802
//#define DEBUG_PRINT_HASH_TABLE 2020

enum SIZE
{
	_HASH_TABLE_SIZE = 128,
	_CONDITION_TO_GENERATE_EXCEPTION_ = 3802
};

/*I implement a struct which will throw an exception at the special case
 * So I will be able to check the state of objects Hash_Table when deep_copy_bucket can generate
 * an exception in more complicated case */
struct Yucky
{
	int a_;
	explicit Yucky(int a)
		: a_(a)
	{};
	Yucky(Yucky &&rhs) noexcept
		: a_(rhs.a_)
	{ rhs.a_ = 0; }
	Yucky(const Yucky &rhs)
		: a_(rhs.a_)
	{
		//generate an exception at the special case
		if (a_ == _CONDITION_TO_GENERATE_EXCEPTION_)
			throw std::invalid_argument("condition to generate exception in copy ctor");
	};
	bool operator==(const Yucky &rhs) const noexcept
	{
		return (a_ == rhs.a_);
	}
};

template<class T>
class Hash_Table;
template<class T>
std::ofstream &operator<<(std::ofstream &out, const Hash_Table<T> &ht);

template<>
struct std::hash<Yucky>
{
	std::size_t operator()(const Yucky &rhs) const noexcept
	{
		std::hash<int> hash_f;
		return hash_f(rhs.a_);
	}
};

template<class Key>
class Hash_Table
{
public :
	/*This multimap will contain the distribution of buckets and its respective values
	 * in sort order. Via this container I will be able to show the result print it to file or STDOUT_FILENO*/
	using info = std::multimap<std::size_t, Key>;

	explicit Hash_Table(std::size_t size = _HASH_TABLE_SIZE);
	~Hash_Table();
	Hash_Table(const Hash_Table &hash_table);
	Hash_Table(Hash_Table&& rhs) noexcept;
	Hash_Table& operator=(Hash_Table&& rhs) noexcept;
	Hash_Table& operator=(const Hash_Table &ht);
	const std::size_t &size() const noexcept;
	void showDistribution(info &map) const;
	friend std::ofstream &operator<<<>(std::ofstream &out, const Hash_Table<Key> &ht);
private :

	class Node
	{
		Node *left_ = nullptr;
		Node *right_ = nullptr;
		Key value;
	public:
		explicit Node(const Key &t);
		explicit Node(Key &&t) noexcept;
		Node() = delete;
		const Node *get_right() const noexcept;
		void set_right(Node *right) noexcept;
		void set_left(Node *left) noexcept;
		const Node *get_left() const noexcept;
		Node *get_left() noexcept;
		Node *get_right() noexcept;
		const Key &get_value() const noexcept;
		Node *ptr_to_last_in_bucket(const Node *ptr_from) const noexcept;
	};

	Node *deep_copy_bucket(const Node *bucket_ptr) const;
	void destroy_bucket(Node *bucket_ptr) const noexcept;

	class NewHandlerHolder
	{
	public:
		explicit NewHandlerHolder(std::new_handler ptr)
			: currentHandler(ptr)
		{}
		NewHandlerHolder(const NewHandlerHolder &holder) = delete;
		NewHandlerHolder &operator=(const NewHandlerHolder &holder) = delete;
		~NewHandlerHolder()
		{ std::set_new_handler(currentHandler); }
	private :
		std::new_handler currentHandler = nullptr;
	};


public:
	class Iterator
	{
		using value_type = Key;
		using pointer = Key *;
		using reference = Key &;
		using difference_type = std::size_t;
		using iterator_category = std::bidirectional_iterator_tag;

	public :
		Iterator() = default;
		Iterator(std::size_t n, std::size_t max, Node *ptr, Node **hash_p);
		Iterator(const Iterator &it) = default;
		Iterator &operator=(const Iterator &it) = default;

		Key &operator*(); // this operator will cause runtime_error in case when we are about to dereference nullptr
		const Key &operator*() const;

		Node *operator->();
		const Node *operator->() const;

		Iterator &operator++() noexcept;
		const Iterator operator++(int);

		Iterator &operator--() noexcept;
		const Iterator operator--(int);

		bool operator==(const Iterator &it) const noexcept;
		bool operator!=(const Iterator &it) const noexcept;


	private :
		std::size_t nbucket_ = 0; // this variable will maintain the current number of bucket
		std::size_t max_buckets = _HASH_TABLE_SIZE;
		Node *ptr_ =
			nullptr;          // this is the main part of this iterator due to I'm going to go through the left and right pointer
		Node **hash_t = nullptr;     // this pointer will maintain the main array of hash_table
	};

	Iterator findEl(const Key &key, std::size_t &bucket);
	Iterator begin();

	Iterator end();

	template<class U>
	bool insert(U &&key);
	bool erase(const Key &key);
	/*These operators will throw an exception of type std::out_of_range in case when
	 * i is out of bound array hash_t*/
	Node *operator[](const std::size_t i);
	const Node *operator[](const std::size_t i) const;

private :

	Node **hash_t = nullptr; // It's a pointer to the array of pointers (aka hash_table structure)
	std::size_t n_buckets = _HASH_TABLE_SIZE;
	static void mem_handler();
	std::size_t hash_func(const Key &key);

};

#endif //HASH_TABLE_HASH_TABLE_H