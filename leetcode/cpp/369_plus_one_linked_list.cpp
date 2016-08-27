#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        int carryover = plusOneRecursion(head);
        if (carryover) {
            ListNode* n = new ListNode(1);
            n->next = head;
            head = n;
        }
        return head;
    }
private:
    int plusOneRecursion(ListNode* node) {
        if (node == NULL) {
            return 1;
        }
        int carryover = plusOneRecursion(node->next);
        node->val += carryover;
        if (node->val >= 10) {
            node->val -= 10;
            return 1;
        } else {
            return 0;
        }
    }
};

int main() {

    ListNode* n = new ListNode(9);
    // n->next = new ListNode(2);
    // n->next->next = new ListNode(3);

    Solution sol;
    n = sol.plusOne(n);

    while (n) {
        cout << n->val;
        n = n->next;
    }
    cout << endl;

    return 0;
}