#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
// Definition for undirected graph.
typedef struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
} UndirectedGraphNode;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> oldToNewMap;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        oldToNewMap[node] = new UndirectedGraphNode(node->label);
        UndirectedGraphNode *next = NULL, *newNext = NULL;
        while (!q.empty()) {
            next = q.front();
            q.pop();
            newNext = oldToNewMap[next];
            for (UndirectedGraphNode* nei: next->neighbors) {
                if (!oldToNewMap.count(nei)) {
                    oldToNewMap[nei] = new UndirectedGraphNode(nei->label);
                    q.push(nei);
                }
                newNext->neighbors.push_back(oldToNewMap[nei]);
            }
        }
        return oldToNewMap[node];
    }
};

int main() {


  return 0;
}
