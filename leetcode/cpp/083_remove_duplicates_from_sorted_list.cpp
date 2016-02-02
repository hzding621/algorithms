#include <iostream>
#include "../../helpers/list_node.cpp"

using namespace std;

ListNode *deleteDuplicates(ListNode *head) {

	ListNode *p1 = head, *p2 = head;
	while (p2) {
		p2 = p2->next;
		while (p2 && p1->val == p2->val) {
			ListNode *t = p2;
			p2 = p2->next;
			delete t;
		}
		p1->next = p2;
		p1 = p2;
	}
	return head;

}



int main() {

	ListNode *head = new ListNode(1);
	ListNode *t = head->next = new ListNode(1);
	t = t->next = new ListNode(2);
	t = t->next = new ListNode(3);
	t = t->next = new ListNode(3);
	t = t->next = new ListNode(3);
	ListNode *newHead = deleteDuplicates(head);
	newHead->print();
	ListNode::clean(newHead);
}