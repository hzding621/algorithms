#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int i = 0;
        while (i < nums.size()) {
            int j = i;
            while (j+1 < nums.size() && nums[j+1] == nums[j]+1) {
                j++;
            }
            if (i != j) {
                stringstream s;
                s << nums[i] << "->" << nums[j];
                ans.push_back(s.str());
            } else {
                stringstream s;
                s << nums[i];
                ans.push_back(s.str());
            }
            i = j + 1;
        }
        return ans;
    }
};

void print(const vector<string>& v) {
    for (const auto& s: v)
        cout << s << endl;
} 

int main() {

    Solution s;
    vector<int> v = {0,1,2,4,5,7};
    print(s.summaryRanges(v));

    return 0;
}