//
// Created by user on 28/02/2020.
//

#include "Hash_Table.h"


template<class Key>
typename Hash_Table<Key>::Node **Hash_Table<Key>::alloc_ptr = nullptr;

template<class Key>
int Hash_Table<Key>::number_allocations = 0;

template<class Key>
void *Hash_Table<Key>::operator new(std::size_t size)
{
	NewHandlerHolder(std::set_new_handler(mem_handler));
	alloc_ptr = new Node *[_HASH_TABLE_SIZE]{
		nullptr}; // at this string I call operator new[] to allocate memory for the array of Node*
	++number_allocations;
	return ::operator new(size);
}

template<class Key>
Hash_Table<Key>::Hash_Table(std::size_t size)
{

	if (number_allocations) {
		if (size != _HASH_TABLE_SIZE || !alloc_ptr)
			throw std::runtime_error("Redefine operator new in Hash_Table made a very strange thing!!!");
		hash_t = alloc_ptr;
		alloc_ptr = nullptr;
		--number_allocations;
	}
	else {
		NewHandlerHolder(std::set_new_handler(mem_handler));
		hash_t = new Node *[size]{nullptr};
		n_buckets = size;
	}
}

template<class Key>
void Hash_Table<Key>::operator delete(void *ptr) noexcept
{
	::operator delete(ptr);
	delete[](alloc_ptr);
	if (number_allocations)
		--number_allocations;

}

template<class T>
Hash_Table<T>::Hash_Table(const Hash_Table<T> &ht)
	: n_buckets(ht.n_buckets)
{
	NewHandlerHolder(std::set_new_handler(mem_handler));
	hash_t = new Node *[n_buckets]{nullptr};
	for (std::size_t i = 0; i < n_buckets; ++i)
		hash_t[i] = deep_copy_bucket(ht[i]);

}

template<class T>
Hash_Table<T> &Hash_Table<T>::operator=(const Hash_Table<T> &ht)
{
	if (&ht != this) {
		for (std::size_t i = 0; i < n_buckets; ++i)
			destroy_bucket(hash_t[i]);
		delete[] hash_t;

		NewHandlerHolder(std::set_new_handler(mem_handler));
		n_buckets = ht.n_buckets;
		hash_t = new Node *[n_buckets]{nullptr};
		for (std::size_t i = 0; i < n_buckets; ++i)
			hash_t[i] = deep_copy_bucket(ht[i]);

	}
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

template<class T>
typename Hash_Table<T>::Node *Hash_Table<T>::deep_copy_bucket(const Hash_Table<T>::Node *bucket_ptr) const
{
	if (!bucket_ptr)
		return nullptr;
	else {
		NewHandlerHolder(std::set_new_handler(mem_handler));

#ifdef C_PLUS_PLUS_IS_ALLOWED
		std::stack<Node*> nodes;
		while(bucket_ptr){
			nodes.push(new Node(bucket_ptr->get_value()));
			bucket_ptr = bucket_ptr->get_right();
		}
		Node* current_ptr = nodes.top();
		nodes.pop();
		while(nodes.size()) {
			current_ptr->set_left(nodes.top());
			(nodes.top())->set_right(current_ptr);
			current_ptr = nodes.top();
			nodes.pop();
		}
		return current_ptr;
#else
		Node *new_ptr = new Node(bucket_ptr->get_value());
		while (bucket_ptr->get_right()) {
			new_ptr->set_right(new Node((bucket_ptr->get_right())->get_value()));
			(new_ptr->get_right())->set_left(new_ptr);
			bucket_ptr = bucket_ptr->get_right();
			new_ptr = new_ptr->get_right();
		}

		while (new_ptr->get_left())
			new_ptr = new_ptr->get_left();

		return new_ptr;
#endif
	}

}

template<class Key>
Hash_Table<Key>::~Hash_Table<Key>()
{
	for (std::size_t i = 0; i < n_buckets; ++i)
		destroy_bucket(hash_t[i]);

	delete[] hash_t;

}

template<class Key>
void Hash_Table<Key>::mem_handler() noexcept
{
	std::cerr << "Operator new failed. There aren't any vacant memory."
				 "It has happened in redefine operator new for template Hash_Table class" << std::endl;
	std::abort();
}

template<class T>
bool Hash_Table<T>::insert(const T &t)
{
	std::size_t hash_value = 0;
	Iterator it = findEl(t, hash_value);
	if (it != end())
		return false;
	else {
		NewHandlerHolder(std::set_new_handler(mem_handler));
		if (!hash_t[hash_value]) {
			hash_t[hash_value] = new Node(t); // allocate and construct the first element in the bucket
		}
		else {
			Node *new_node = new Node(t);
			new_node->set_right(hash_t[hash_value]);
			(hash_t[hash_value])->set_left(new_node);
			hash_t[hash_value] = new_node;
		}
		return true;
	}
}

template<class T>
typename Hash_Table<T>::Iterator Hash_Table<T>::findEl(const T &el, std::size_t &bucket)
{
	bucket = hash_func(el);

	if (hash_t[bucket]) {
		Iterator it(bucket, n_buckets, hash_t[bucket], hash_t);
		Iterator it_end(bucket + 1, n_buckets, hash_t[bucket + 1], hash_t);
		for (; it != it_end; ++it) {
			if (*it == el)
				return it;
		}
	}
	return end();
}

template<class Key>
Hash_Table<Key>::Node::Node(const Key &t)
	: value(t)
{}

template<class Key>
Hash_Table<Key>::Node::Node(Node *left, Node *right, const Key &key)
	: left_(left), right_(right), value(key)
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
	: ptr_(ptr), hash_t(hash_p)
{
	if (n > max)
		throw std::runtime_error("negative value for the number of bucket");
	nbucket_ = n;
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
	if (ptr_->get_right()) {
		ptr_ = ptr_->get_right();
		return (*this);
	}
	else {
		if (nbucket_ <= max_buckets - 1) {
			++nbucket_;
			ptr_ = hash_t[nbucket_];
		}
		return (*this);
	}
}

template<class T>
const typename Hash_Table<T>::Iterator Hash_Table<T>::Iterator::operator++(int)
{
	Node *save_current_ptr = ptr_;
	if (ptr_->get_right()) {
		ptr_ = ptr_->get_right();
		return Iterator(nbucket_, max_buckets, save_current_ptr, hash_t);
	}
	else {
		if (nbucket_ <= max_buckets - 1) {
			size_t save_nbucket_ = nbucket_;
			++nbucket_;
			ptr_ = hash_t[nbucket_];
			return Iterator(save_nbucket_, max_buckets, save_current_ptr, hash_t);
		}
		return Iterator(nbucket_, max_buckets, save_current_ptr, hash_t);
	}
}

template<class T>
typename Hash_Table<T>::Iterator &Hash_Table<T>::Iterator::operator--() noexcept
{
	if (ptr_->get_left()) {
		ptr_ = ptr_->get_left();
		return (*this);
	}
	else {
		if (nbucket_ > 0) {
			--nbucket_;
			ptr_ = hash_t[nbucket_];
		}
		return (*this);
	}
}
template<class T>
const typename Hash_Table<T>::Iterator Hash_Table<T>::Iterator::operator--(int)
{
	Node *save_current_node = ptr_;
	if (ptr_->get_left()) {
		ptr_ = ptr_->get_left();
		return Iterator(nbucket_, max_buckets, save_current_node, hash_t);
	}
	else {
		if (nbucket_ > 0) {
			size_t save_nbucket_ = nbucket_;
			--nbucket_;
			ptr_ = hash_t[nbucket_];
			return Iterator(save_nbucket_, max_buckets, save_current_node, hash_t);
		}
		return Iterator(nbucket_, max_buckets, ptr_, hash_t);
	}
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
std::size_t Hash_Table<T>::hash_func(const T &key) noexcept
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
	else {
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
}

