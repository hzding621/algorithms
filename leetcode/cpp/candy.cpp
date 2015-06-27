#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        map<int, vector<int>> valueToIndices;
        for (int i=0; i<ratings.size(); i++) {
            valueToIndices[ratings[i]].push_back(i);
        }

        vector<int> candies(ratings.size(), 1);
        for (auto it = valueToIndices.begin(); it != valueToIndices.end(); it++) {
            for (int k: it->second) {
                int v = 1;
                if (k > 0 && ratings[k] > ratings[k-1])
                    v = max(v, candies[k-1]+1);
                if (k < ratings.size()-1 && ratings[k] > ratings[k+1])
                    v = max(v, candies[k+1]+1);
                candies[k] = v;
            }
        }
        int sum = 0;
        for (int i: candies) {
            sum += i;
        }
        return sum;
    }
};

int main() {
    vector<int> v = {1,3,5};
    Solution sol;
    cout << sol.candy(v) << endl;
}