// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <util/list_node.cpp>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sent = new ListNode(0), *t = sent;
        int co = 0;
        while (l1 && l2) {
            int s = l1->val + l2->val + co;
            if (s < 10) {
                t->next = new ListNode(s);
                co = 0; 
            } else {
                t->next = new ListNode(s-10);
                co = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
            t = t->next;
        }
        while (l1) {
            int s = l1->val + co;
            if (s < 10) {
                t->next = new ListNode(s);
                co = 0; 
            } else {
                t->next = new ListNode(s-10);
                co = 1;
            }
            l1 = l1->next;
            t = t->next;
        }
        while (l2) {
            int s = l2->val + co;
            if (s < 10) {
                t->next = new ListNode(s);
                co = 0; 
            } else {
                t->next = new ListNode(s-10);
                co = 1;
            }
            l2 = l2->next;
            t = t->next;
        }
        if (co) {
            t->next = new ListNode(co);
        }
        return sent->next;
    }
};