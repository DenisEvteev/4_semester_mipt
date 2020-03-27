//
// Created by user on 28/02/2020.
//

#include "Hash_Table.h"

template<class T>
const std::size_t &Hash_Table<T>::size() const noexcept
{ return n_buckets; }


template<class T>
Hash_Table<T>::Hash_Table(Hash_Table<T>&& rhs) noexcept : hash_t(rhs.hash_t), n_buckets(rhs.n_buckets)
{
	rhs.hash_t = nullptr;
	rhs.n_buckets = 0;
}

template<class T>
Hash_Table<T>& Hash_Table<T>::operator=(Hash_Table<T>&& rhs)noexcept {
	if (this == &rhs) {
		return *this;
	}
	for (std::size_t i = 0; i < n_buckets; ++i)
		destroy_bucket(hash_t[i]);

	delete[] hash_t;
	hash_t = rhs.hash_t;
	n_buckets = rhs.n_buckets;

	rhs.n_buckets = 0;
	rhs.hash_t = nullptr;
	return (*this);

}

template<class Key>
Hash_Table<Key>::Hash_Table(std::size_t size)
{
	if (size == 0)
		throw std::invalid_argument("Cannot create Hash_Table with zero number of buckets");

	NewHandlerHolder handler(std::set_new_handler(mem_handler));
	/*[+1] means reserving additional memory for Iterator to the end of this container*/
	hash_t = new Node *[(size + 1)]{nullptr};
	n_buckets = size;
}

template<class T>
typename Hash_Table<T>::Node *Hash_Table<T>::operator[](const std::size_t i)
{
	return const_cast<Node *>((static_cast<const Hash_Table<T> &>(*this)).operator[](i));
}

template<class T>
const typename Hash_Table<T>::Node *Hash_Table<T>::operator[](const std::size_t i) const
{
	if (i >= n_buckets)
		throw std::out_of_range("You aren't allowed to access this part of memory");
	return hash_t[i];
}

/*Copy constructor gives a basic guarantee of security in case of throwing exception
 * in the case when method deep_copy_bucket generates an exception (or maybe another way of such a trouble)
 * I set n_buckets to zero and hash_t to nullptr
 * we can easily perform then operator= for this object and fill it with new set of elements*/
template<class T>
Hash_Table<T>::Hash_Table(const Hash_Table<T> &ht)
	: n_buckets(ht.n_buckets)
{
	std::size_t i = 0;
	NewHandlerHolder handler(std::set_new_handler(mem_handler));
	try {
		hash_t = new Node *[(n_buckets + 1)]{nullptr};
		for (; i < n_buckets; ++i)
			hash_t[i] = deep_copy_bucket(ht[i]);
	}
	catch (...) {
		for (std::size_t ip_ = 0; ip_ < i; ++ip_) {
			destroy_bucket(hash_t[ip_]);
		}
		delete[] hash_t;
		hash_t = nullptr;
		n_buckets = 0;
		throw;
	}
}

/*This method represents the strict guarantee of security about exceptions
 * If the latter will happen then the object for which we have called this operator
 * will remain in the state it was the step before I mean we will follow two basic rules about guarantee
 * working with exceptions ---- 1) no memory leaks
 *                              2) no corrupted data in any fields of the object*/
template<class T>
Hash_Table<T> &Hash_Table<T>::operator=(const Hash_Table<T> &ht)
{
	if (&ht == this)
		return (*this);

	NewHandlerHolder handler(std::set_new_handler(mem_handler));
	Node **try_copy = new Node *[(ht.n_buckets + 1)]{nullptr};
	std::size_t i = 0;
	try {
		for (; i < ht.n_buckets; ++i)
			try_copy[i] = deep_copy_bucket(ht[i]);

	}
	catch (...) {
		for (std::size_t ip_ = 0; ip_ < i; ++ip_) {
			destroy_bucket(try_copy[ip_]);
		}
		delete[] try_copy;
		throw;
	}

	for (std::size_t i = 0; i < n_buckets; ++i)
		destroy_bucket(hash_t[i]);
	delete[] hash_t;

	n_buckets = ht.n_buckets;
	hash_t = try_copy;
	return (*this);
}

template<class T>
void Hash_Table<T>::destroy_bucket(Hash_Table<T>::Node *bucket_ptr) const noexcept
{
	Node *save_node = nullptr;
	while (bucket_ptr) {
		save_node = bucket_ptr->get_right();
		delete bucket_ptr;
		bucket_ptr = save_node;
	}
}

/*deep_copy_bucket can throw several types of exceptions :
 * std::bad_alloc() and some other user specified from constructor of object T*/
template<class T>
typename Hash_Table<T>::Node *Hash_Table<T>::deep_copy_bucket(const Hash_Table<T>::Node *bucket_ptr) const
{
	if (!bucket_ptr)
		return nullptr;

#ifdef C_PLUS_PLUS_IS_ALLOWED
	std::stack<Node*> nodes;
	try{
		while(bucket_ptr){
			nodes.push(new Node(bucket_ptr->get_value()));
			bucket_ptr = bucket_ptr->get_right();
		}
	}catch(...){
		while(!nodes.empty()){
			Node* deleted = nodes.top();
			nodes.pop();
			delete deleted;
		}
		throw;
	}

	Node* current_ptr = nodes.top();
	nodes.pop();
	while(!nodes.empty()) {
		current_ptr->set_left(nodes.top());
		(nodes.top())->set_right(current_ptr);
		current_ptr = nodes.top();
		nodes.pop();
	}
	return current_ptr;
#else
	Node *new_ptr = new Node(bucket_ptr->get_value());
	try {
		while (bucket_ptr->get_right()) {
			new_ptr->set_right(new Node((bucket_ptr->get_right())->get_value()));
			(new_ptr->get_right())->set_left(new_ptr);
			bucket_ptr = bucket_ptr->get_right();
			new_ptr = new_ptr->get_right();
		}
	}
	catch (...) {
		destroy_bucket(new_ptr);
		throw;
	}
	while (new_ptr->get_left())
		new_ptr = new_ptr->get_left();

	return new_ptr;
#endif
}



template<class Key>
Hash_Table<Key>::~Hash_Table<Key>()
{
	if(!hash_t)
		return;
	for (std::size_t i = 0; i < n_buckets; ++i)
		destroy_bucket(hash_t[i]);
	delete[] hash_t;
}

template<class Key>
void Hash_Table<Key>::mem_handler()
{
	std::cerr << "Operator new failed. There aren't any vacant memory."
				 "It has happened in redefine operator new for template Hash_Table class" << std::endl;
	throw std::bad_alloc();
}

template<class T>
template<class U>
bool Hash_Table<T>::insert(U &&el)
{
	std::size_t hash_value = 0;
	Iterator it = findEl(el, hash_value);
	if (it != end())
		return false;

	NewHandlerHolder handler(std::set_new_handler(mem_handler));
	if (!hash_t[hash_value]) {
		hash_t[hash_value] =
			new Node(std::forward<U>(el)); // fucking Denis You are wrong !!! we call exactly not we want
		return true;
	}

	Node *new_node = new Node(std::forward<U>(el));
	new_node->set_right(hash_t[hash_value]);
	(hash_t[hash_value])->set_left(new_node);
	hash_t[hash_value] = new_node;
	return true;

}

template<class T>
typename Hash_Table<T>::Iterator Hash_Table<T>::findEl(const T &el, std::size_t &bucket)
{
	if (n_buckets == 0) // this case can appear when copy constructor rethrow an exception -- a very bad case
		throw std::runtime_error("you shouldn't find elements in empty Hash_Table");

	bucket = hash_func(el);
	if (!hash_t[bucket])
		return end();

	Iterator it(bucket, n_buckets, hash_t[bucket], hash_t);
	Iterator it_end(bucket + 1, n_buckets, hash_t[bucket + 1], hash_t);
	for (; it != it_end; ++it) {
		if (*it == el)
			return it;

	}
	return end();
}

template<class Key>
Hash_Table<Key>::Node::Node(const Key &t)
	: value(t)
{}

template<class T>
Hash_Table<T>::Node::Node(T &&t) noexcept
	: value(std::move(t))
{}

template<class T>
void Hash_Table<T>::Node::set_left(Hash_Table<T>::Node *left) noexcept
{
	left_ = left;
}

template<class T>
void Hash_Table<T>::Node::set_right(Hash_Table<T>::Node *right) noexcept
{
	right_ = right;
}

template<class T>
Hash_Table<T>::Iterator::Iterator(size_t n, size_t max, Node *ptr, Node **hash_p)
	: nbucket_(n), max_buckets(max), ptr_(ptr), hash_t(hash_p)
{
	if (n > max)
		throw std::runtime_error("negative value for the number of bucket");
}

template<class T>
T &Hash_Table<T>::Iterator::operator*()
{
	return const_cast<T &>(static_cast<const Iterator &>(*this).operator*());
}

template<class T>
const T &Hash_Table<T>::Iterator::operator*() const
{
	if (!ptr_)
		throw std::runtime_error("dereferencing nullptr  -- SIGSEGV");
	return ptr_->get_value();
}

template<class T>
typename Hash_Table<T>::Node *Hash_Table<T>::Iterator::operator->()
{
	return const_cast<typename Hash_Table<T>::Node *>(static_cast<const Iterator &>(*this).operator->());
}

template<class T>
const typename Hash_Table<T>::Node *Hash_Table<T>::Iterator::operator->() const
{
	if (!ptr_)
		throw std::runtime_error("ptr_ is nullptr [const]");
	return ptr_;
}

template<class T>
typename Hash_Table<T>::Iterator &Hash_Table<T>::Iterator::operator++() noexcept
{
	if (ptr_ && ptr_->get_right()) {
		ptr_ = ptr_->get_right();
		return (*this);
	}

	if (nbucket_ <= max_buckets - 1) {
		++nbucket_;
		ptr_ = hash_t[nbucket_];
	}
	return (*this);

}

template<class T>
const typename Hash_Table<T>::Iterator Hash_Table<T>::Iterator::operator++(int)
{
	Node *save_current_ptr = ptr_;

	if (ptr_ && ptr_->get_right()) {
		ptr_ = ptr_->get_right();
		return Iterator(nbucket_, max_buckets, save_current_ptr, hash_t);
	}

	if (nbucket_ <= max_buckets - 1) {
		size_t save_nbucket_ = nbucket_;
		++nbucket_;
		ptr_ = hash_t[nbucket_];
		return Iterator(save_nbucket_, max_buckets, save_current_ptr, hash_t);
	}
	return Iterator(nbucket_, max_buckets, save_current_ptr, hash_t);

}

template<class T>
typename Hash_Table<T>::Iterator &Hash_Table<T>::Iterator::operator--() noexcept
{
	if (ptr_ && ptr_->get_left()) {
		ptr_ = ptr_->get_left();
		return (*this);
	}

	if (nbucket_ > 0) {
		--nbucket_;
		ptr_ = hash_t[nbucket_]->ptr_to_last_in_bucket(hash_t[nbucket_]);
	}
	return (*this);
}

template<class T>
typename Hash_Table<T>::Node *Hash_Table<T>::Node::ptr_to_last_in_bucket(const Node *ptr_from) const noexcept
{
	if (!ptr_from)
		return nullptr;
	while (ptr_from->get_right()) {
		ptr_from = ptr_from->get_right();
	}
	return const_cast<Node *>(ptr_from);

}

template<class T>
const typename Hash_Table<T>::Iterator Hash_Table<T>::Iterator::operator--(int)
{
	Node *save_current_node = ptr_;
	if (ptr_ && ptr_->get_left()) {
		ptr_ = ptr_->get_left();
		return Iterator(nbucket_, max_buckets, save_current_node, hash_t);
	}
	if (nbucket_ > 0) {
		size_t save_nbucket_ = nbucket_;
		--nbucket_;
		ptr_ = hash_t[nbucket_]->ptr_to_last_in_bucket(hash_t[nbucket_]);
		return Iterator(save_nbucket_, max_buckets, save_current_node, hash_t);
	}
	return Iterator(nbucket_, max_buckets, ptr_, hash_t);
}

template<class T>
bool Hash_Table<T>::Iterator::operator==(const Hash_Table<T>::Iterator &it) const noexcept
{
	return (ptr_ == it.ptr_ && nbucket_ == it.nbucket_ && hash_t == it.hash_t && max_buckets == it.max_buckets);
}

template<class T>
bool Hash_Table<T>::Iterator::operator!=(const Hash_Table<T>::Iterator &it) const noexcept
{
	return !(*this == it);
}

template<class T>
typename Hash_Table<T>::Iterator Hash_Table<T>::begin()
{
	return Iterator(0, n_buckets, hash_t[0], hash_t);
}

template<class T>
typename Hash_Table<T>::Iterator Hash_Table<T>::end()
{
	return Iterator(n_buckets, n_buckets, hash_t[n_buckets], hash_t);
}

template<class T>
std::size_t Hash_Table<T>::hash_func(const T &key)
{
	static std::hash<T> hash_f;
	return hash_f(key) % n_buckets;
}

template<class T>
const typename Hash_Table<T>::Node *Hash_Table<T>::Node::get_right() const noexcept
{
	return right_;
}

template<class T>
const typename Hash_Table<T>::Node *Hash_Table<T>::Node::get_left() const noexcept
{
	return left_;
}

template<class T>
typename Hash_Table<T>::Node *Hash_Table<T>::Node::get_left() noexcept
{
	return const_cast<Node *>(static_cast<const Node *>(this)->get_left());
}
template<class T>
typename Hash_Table<T>::Node *Hash_Table<T>::Node::get_right() noexcept
{
	return const_cast<Node *>(static_cast<const Node *>(this)->get_right());
}

template<class T>
const T &Hash_Table<T>::Node::get_value() const noexcept
{
	return value;
}

template<class T>
bool Hash_Table<T>::erase(const T &t)
{
	std::size_t bucket = 0;
	Iterator it = findEl(t, bucket);
	if (it == end())
		return false;

	if (it->get_right())
		(it->get_right())->set_left(it->get_left());

	if (it->get_left())
		(it->get_left())->set_right(it->get_right());

	int flag_erase_the_first_el = 0;
	Node *save_ptr = it->get_right();
	if (!it->get_left())
		flag_erase_the_first_el = 1;

	delete it.operator->();
	if (flag_erase_the_first_el)
		hash_t[bucket] = save_ptr;
	return true;
}

template<class T>
void Hash_Table<T>::showDistribution(info &map) const
{
	if (!map.empty())
		map.clear();
	for (std::size_t i = 0; i < n_buckets; ++i) {
		Iterator it(i, n_buckets, hash_t[i], hash_t);
		Iterator it_next(i + 1, n_buckets, hash_t[i + 1], hash_t);
		while (it != it_next) {
			try {
				T value = *it; // it's a very bad string of code [but this time It would be like this]
				map.insert(std::make_pair(i, value));
			}
			catch (const std::runtime_error &er) {
				break;
			}
			++it;
		}
	}
}

template<class T>
std::ofstream &operator<<(std::ofstream &out, const Hash_Table<T> &ht)
{
	std::multimap<std::size_t, T> map;
	ht.showDistribution(map);
	for (std::size_t i = 0; i < ht.size(); ++i) {
		auto it = map.equal_range(i);
		out << "[ " << i << " ] === ";
		if (it.first == map.end() || it.first == it.second) {
			out << "null\n";
			continue;
		}
		for (auto ip = it.first; ip != it.second;) {
			out << (*ip).second;
			++ip;
			if (ip != it.second)
				out << ", ";
			else {
				out << ";   { " << map.count(i) << " }\n";
			}
		}
	}
	return out;
}

template
class Hash_Table<int>;
template std::ofstream &operator<<(std::ofstream &out, const Hash_Table<int> &ht);
template
class Hash_Table<Yucky>;

template bool Hash_Table<int>::insert<int>(int &&el);
template bool Hash_Table<int>::insert<int &>(int &el);
template bool Hash_Table<Yucky>::insert<Yucky>(Yucky &&el);
template bool Hash_Table<Yucky>::insert<Yucky &>(Yucky &el);


