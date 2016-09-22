#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || A[0].empty() || B.empty() || B[0].empty()) return {};
        int M = A.size(), N = B[0].size(), K = A[0].size();
        vector<vector<int>> AGroupByCol(K);
        vector<vector<int>> BGroupByRow(K);
        vector<vector<int>> result;
        for (int i = 0; i < M; i++) {
            result.emplace_back(N);
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < K; j++) {
                if (A[i][j]) AGroupByCol[j].push_back(i);
            }
        }

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < N; j++) {
                if (B[i][j]) BGroupByRow[i].push_back(j);
            }
        }

        for (int s = 0; s < K; s++) {
            for (int i: AGroupByCol[s]) {
                for (int j: BGroupByRow[s]) {
                    result[i][j] += A[i][s] * B[s][j];
                }
            }
        }
        return result;
    }
};

int main() {

    vector<vector<int>> A = {
            {1,  0, 0},
            {-1, 0, 3}
    };

    vector<vector<int>> B = {
            {7, 0, 0},
            {0, 0, 0},
            {0, 0, 1}
    };

    Solution solution;
    vector<vector<int>> AB = solution.multiply(A, B);

    for (int i = 0; i < AB.size(); i++) {
        for (int j = 0; j < AB[0].size(); j++) {
            cout << AB[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}