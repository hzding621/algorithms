#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(0), *evenHead = new ListNode(0);
        ListNode* oddPtr = oddHead, *evenPtr = evenHead;
        bool nextIsOdd = true;
        while (head) {
            if (nextIsOdd) {
                oddPtr->next = head;
                oddPtr = oddPtr->next;
            } else {
                evenPtr->next = head;
                evenPtr = evenPtr->next;
            }
            nextIsOdd = !nextIsOdd;
            head = head->next;
        }
        evenPtr->next = NULL;
        oddPtr->next = evenHead->next;
        ListNode* result = oddHead->next;
        delete oddHead;
        delete evenHead;
        return result;
    }
};

int main() {

    ListNode *head = new ListNode(1);
    ListNode *headCopy = head;
    head = head->next = new ListNode(2);
    head = head->next = new ListNode(3);
    head = head->next = new ListNode(4);
    head = head->next = new ListNode(5);

    Solution sol;
    head = sol.oddEvenList(headCopy);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}