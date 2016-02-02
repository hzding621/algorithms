#ifndef _list_node_
#define _list_node_

#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	void print() {
		std::cout << val << "->";
		if (next != NULL)
			next->print();
		else
			std::cout << "NULL" << std::endl;
	}
	static void clean(ListNode* head) {
		if (head->next)
			clean(head->next);
		delete head;
	}
};

#endif