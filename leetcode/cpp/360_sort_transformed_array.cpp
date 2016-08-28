#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        
        if (a == 0) {
            return linearCase(nums, n, b, c);
        } else {
            return quadraticCase(nums, n, a, b, c);
        }
    }
private:
    int apply(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }

    vector<int> linearCase(vector<int>& nums, int n, int b, int c) {
        vector<int> result = nums;
        for (int i = 0; i < n; i++) {
            result[i] *= b;
            result[i] += c;
        }
        if (b < 0) {
            reverse(result.begin(), result.end());
        }
        return result;
    }

    vector<int> quadraticCase(vector<int>& nums, int n, int a, int b, int c) {
        // center at -b/(2a)
        int i = 0, j;
        double center = - (double) b / (2 * a);
        while (i < n && nums[i] < center) {
            i++;
        }
        j = i--;
        bool aIsNegative = a < 0;
        vector<int> result;
        while (i >= 0 && j < n) {
            int y1 = apply(nums[i], a, b, c),
                y2 = apply(nums[j], a, b, c);
            if ((y1 < y2) ^ aIsNegative) {
                result.push_back(y1);
                i--;
            } else {
                result.push_back(y2);
                j++;
            }
        }
        while (i >= 0) {
            result.push_back(apply(nums[i--], a ,b, c));
        }
        while (j < n) {
            result.push_back(apply(nums[j++], a, b, c));
        }
        if (aIsNegative) {
            reverse(result.begin(), result.end());
        }
        return result;
    }
};

int main() {

    vector<int> v = {-4, -2, 0, 2, 4};
    int a = 1, b = 3, c = 5;
    Solution sol;
    auto vi = sol.sortTransformedArray(v, a, b, c);
    for (int i: vi) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}