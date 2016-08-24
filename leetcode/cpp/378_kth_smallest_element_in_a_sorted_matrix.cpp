#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Same as Merge K List
        // Not ideal solution

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            pq.push(make_tuple(matrix[0][i], 0, i));
        } 
        for (int s = 0; s < k-1; s++) {
            int i, j;
            tie(ignore, i, j) = pq.top();
            pq.pop();
            if (i < n-1) {
                pq.push(make_tuple(matrix[i+1][j], i+1, j));
            }
        }
        return get<0>(pq.top());
    }
};

int main() {

    vector<vector<int>> v = {
        { 1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    Solution sol;
    cout << sol.kthSmallest(v, 8) << endl; 

    return 0;
}