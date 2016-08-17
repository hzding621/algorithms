#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if (headA == NULL || headB == NULL)
    		return NULL;

        int stepsA = 0, stepsB = 0;
        ListNode *headACopy = headA, *headBCopy = headB;
        while (headACopy->next != NULL) {
        	stepsA++;
        	headACopy = headACopy->next;
        }
        while (headBCopy->next != NULL) {
        	stepsB++;
        	headBCopy = headBCopy->next;
        }
        if (headACopy != headBCopy)
        	return NULL;

        if (stepsA >= stepsB) {
        	int steps = stepsA - stepsB;
        	while (steps-- > 0) {
        		headA = headA->next;
        	}
        } else {
        	int steps = stepsB - stepsA;
        	while (steps-- > 0) {
        		headB = headB->next;
        	}
        }

        while (headA != headB) {
        	headA = headA->next;
        	headB = headB->next;
        }
        return headA;
    }
};

int main() {

	Solution sol;

	struct ListNode* n = new struct ListNode(2);
	n->next = new struct ListNode(3);
	n->next->next = new struct ListNode(4);
	struct ListNode* n2 = new struct ListNode(5);
	n2->next = new struct ListNode(6);
	n2->next->next = n->next;

	ListNode* intersection = sol.getIntersectionNode(n, n2);
	cout << intersection->val << endl;

	return 0;
}