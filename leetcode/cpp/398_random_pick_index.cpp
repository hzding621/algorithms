#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) : _v(nums) {
        srand(time(NULL));
    }

    int pick(int target) {
        int count = 1;
        int index = -1;
        for (int i = 0; i < _v.size(); i++) {
            if (_v[i] == target) {
                if (rand() % count == 0) {
                    index = i;
                }
                count++;
            }
        }
        return index;
    }
private:
    vector<int> _v;
};

int main() {

    vector<int> v = {1,2,3,3,3};
    Solution solution(v);

    cout << solution.pick(3) << endl;
    cout << solution.pick(1) << endl;


    return 0;
}
