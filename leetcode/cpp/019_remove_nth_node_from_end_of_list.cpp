#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            len++;
        }
        if (n == len) {
            ListNode* toRemove = head;
            ListNode* toReturn = head->next;
            delete toRemove;
            return toReturn;
        }
        cur = head;
        for (int i = 0; i < len - n - 1; i++) {
            cur = cur->next;
        }
        ListNode* toRemove = cur->next;
        cur->next = cur->next->next;
        delete toRemove;
        return head;
    }
};

int main() {

    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* newHead = solution.removeNthFromEnd(list, 1);
    while (newHead) {
        cout << newHead->val << ",";
        newHead = newHead->next;
    }

}