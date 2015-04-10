#ifndef _list_node_
#define _list_node_

#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	void print() {
		std::cout << "[";
		print_rec();
		std::cout << "]" << std::endl;
	}
	void print_rec() {
		std::cout << val;
		if (next) {
			std::cout << ",";
			next->print_rec();
		}
	}
	void clean() {
		if (next)
			next->clean();
		delete next;
		next = NULL;
	}
};

#endif