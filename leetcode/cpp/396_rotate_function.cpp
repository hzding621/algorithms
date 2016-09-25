#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0; // store the sum of elements in A
        int F = 0; // starts at F[0], iterates through F[1],F[2]...
        int n = A.size();
        for (int i = 0; i < n; i++) {
            F += i * A[i];
            sum += A[i];
        }

        int maxF = F;
        for (int i = n-1; i >= 0; i--) {
            F += sum - n * A[i]; // computes difference between consecutive F's
            maxF = max(maxF, F);
        }
        return maxF;
    }
};

int main() {

    vector<int> v = {4, 3, 2, 6};
    Solution solution;
    cout << solution.maxRotateFunction(v) << endl;

    return 0;
}