/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        ListNode* dm = new ListNode(0), *t = dm;
        int k = lists.size();
        vector<ListNode*> heads;
        for (int i=0; i<k; i++) {
            heads.push_back(lists[i]);
            if (lists[i]) pq.push(make_pair(lists[i]->val, i));
        }
        while (pq.size()) {
            pair<int,int> p = pq.top();
            pq.pop();
            t->next = new ListNode(p.first);
            t = t->next;
            heads[p.second] = heads[p.second]->next;
            if (heads[p.second]) pq.push(make_pair(heads[p.second]->val, p.second));
        }
        t = dm->next;
        delete dm;
        return t;
    }
};