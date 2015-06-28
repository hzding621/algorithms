#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:

    bool postOrderDFS(int cur, vector<char>& states, const vector<vector<bool>>& edges, vector<int>& path) {
        states[cur] = 1;
        for (int j=0; j<edges[cur].size(); j++) {
            if (edges[cur][j])
                if (states[j] == 1 || (states[j] == 0 && !postOrderDFS(j, states, edges, path)))
                    return false;
        }
        path.push_back(cur);
        states[cur] = 2;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<bool>> edges(numCourses, vector<bool>(numCourses, false));
        for (auto& p: prerequisites)
            edges[p.first][p.second] = true;
        vector<char> states(numCourses, 0); // 0 not visited, 1 pre-visited, 2 post-visited
        vector<int> path;
        for (int i=0; i<numCourses; i++) {
            if (!states[i] && !postOrderDFS(i, states, edges, path))
                return {};
        }
        return path;
    }

};

void print(const vector<int>& v) {
    for (int i: v)
        cout << i << " ";
    cout << endl;
}

int main() {

    vector<pair<int,int>> prereq;
    prereq.push_back(make_pair(0,1));
    prereq.push_back(make_pair(0,2));
    prereq.push_back(make_pair(0,3));
    prereq.push_back(make_pair(1,4));
    prereq.push_back(make_pair(2,4));
    Solution sol;
    print(sol.findOrder(5, prereq));
}
