#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        _original = nums;   
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = _original;
        for (int i = 1; i <= shuffled.size(); i++) {
            swap(shuffled, rand() % i, i - 1);
        }
        return shuffled;
    }
private:
    vector<int> _original;

    void swap(vector<int>& v, int i, int j) {
        if (i == j) return;
        int k = v[i];
        v[i] = v[j];
        v[j] = k;
    }
};

int main() {

    vector<int> v = {1,2,3,4,5,6};
    Solution sol(v);
    for (int i = 0; i < 10; i++) {
        auto vi = sol.shuffle();
        for (int j: vi) {
            cout << j << ",";
        }
        cout << endl;
    }

    return 0;
}