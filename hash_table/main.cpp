#include <iostream>
#include "Hash_Table.hpp"


int main()
{

	auto ht = new Hash_Table<int>;
	if (ht->insert(34)) {
		std::cout << "the insertion have been made ;)))" << std::endl;
	}
	if (ht->insert(34))
		std::cout << "strange insertion" << std::endl;

	std::size_t bucket = 0;
	Hash_Table<int>::Iterator it = ht->findEl(34, bucket);
	/*I'm checking some how some functions are work*/



	delete ht;
	return 0;

}
