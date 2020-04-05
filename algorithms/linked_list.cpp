//
// Created by user on 05/04/2020.
//
#include <iostream>

struct Node
{
	int value;
	struct Node *next;
};

struct Node *cycleStart(struct Node *head);

int main()
{
	/*Check this algorithm for a triangle*/
	struct Node *head = new struct Node[3];
	head->value = 0;

	head->next = &head[1];
	head->next->value = 1;

	head->next->next = &head[2];
	head->next->next->value = 2;
	head[2].next = &head[0];
	std::cout << cycleStart(&head[0])->value;
	delete[] head;
	return 0;
}

struct Node *cycleStart(struct Node *head)
{
	if (!head || !head->next)
		return NULL;
	struct Node *p1 = head;
	struct Node *p2 = head;

	while (1) {
		p1 = p1->next;
		p2 = (p2->next)->next;

		if (!p2 || !p2->next)
			return NULL;
		if (p1 == p2)
			break;

	}
	p2 = head;
	while (p2 != p1) {
		p2 = p2->next;
		p1 = p1->next;
	}
	return p1;
}