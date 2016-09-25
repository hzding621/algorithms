#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!hasAtLeastkNodes(head, k)) return head;
        ListNode* tail = head;
        int n = k;
        while (n --> 1) {
            tail = tail->next;
        }
        tail->next = reverseKGroup(tail->next, k);
        return reverseFirstK(head, k);
    }

private:
    ListNode* reverseFirstK(ListNode *head, int k) {
        ListNode* prev = head, *cur = head->next, *next;
        while (k --> 1) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = cur;
        return prev;
    }

    bool hasAtLeastkNodes(ListNode* head, int k) {
        while (k --> 0) {
            if (head == nullptr) return false;
            head = head->next;
        }
        return true;
    }
};

int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = new ListNode(6);

    Solution solution;
    list = solution.reverseKGroup(list, 1);
    while (list) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;

}