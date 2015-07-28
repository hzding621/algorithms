#include <iostream>
#include "list_node.cpp"

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node->next)
            return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    
}
