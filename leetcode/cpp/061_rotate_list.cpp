#include <iostream>
#include <string>
#include "util/list_node.cpp"

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* t = head;
        int len = 0;
        while (t != NULL) {
            t = t->next;
            len++;
        }
        if (len == 0)
            return NULL;
        k = k % len;
        if ( k == 0)
            return head;
        t = head;
        while (len - k > 1) {
            t = t->next;
            len--;
        }
        ListNode* u = t->next;
        t->next = NULL;
        t = u;
        while ( t->next != NULL)
            t = t->next;
        t->next = head;

        return u;

    }
};

int main() {

    Solution s;

    ListNode* n = new ListNode(1);
    n->next = new ListNode(2);
    n->print();
    n = s.rotateRight(n, 3);
    n->print();

	return 0;
}