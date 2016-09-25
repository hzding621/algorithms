#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        head->next->next = swapPairs(head->next->next);
        return swapFirstTwo(head);
    }
private:
    ListNode* swapFirstTwo(ListNode* head) {
        ListNode* second = head->next;
        head->next = second->next;
        second->next = head;
        return second;
    }
};

int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    Solution solution;
    list = solution.swapPairs(list);
    while (list) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;

}