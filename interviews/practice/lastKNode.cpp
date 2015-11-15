#include <iostream>
#include <queue>
#include <cassert>
using namespace std;
typedef struct node {
	int value;
	struct node* next;
	node(int n) {value = n; next = NULL;}
} node;

node* lastKNode(node* head, int k) {
	queue<node*> q;
	// spec: if length < k, return null
	while (k > 0) {
		if (head == NULL)
			return NULL;
		q.push(head);
		head = head->next;
		k--;
	}
	while (q.back()->next) {
		q.pop();
		q.push(q.back()->next);
	}
	return q.front();
}
int main() {
	node* n1 = new node(1);
	node* n2 = new node(2);
	node* n3 = new node(3);
	node* n4 = new node(4);
	node* n5 = new node(5);
	node* n6 = new node(6);
	node* n7 = new node(7);
	node* n8 = new node(8);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;

	node* t = lastKNode(n1, 2);
	cout << t->value << " sol: 7" << endl;
	t = lastKNode(n1, 3);
	cout << t->value << " sol: 6 "<< endl;
	t = lastKNode(n1, 8);
	cout << t->value << " sol: 1" << endl;
	assert(lastKNode(n1, 9) == NULL);
}