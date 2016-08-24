#include <iostream>
#include <vector>
#include <climits>

using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* chosen = NULL, *iter = _head;
        int counter = 1;
        while (iter) {
            if (rand() % counter == 0) {
                chosen = iter;
            }
            iter = iter->next;
            counter++;
        }
        return chosen->val;
    }
private:
    ListNode* _head;

};

int main() {

    return 0;
}