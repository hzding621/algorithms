#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> result;
        while (people.size()) {

            // put the people with no predecessor and smallest height to the tail of vector
            auto max_iter = max_element(people.begin(), people.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
                return b.second < a.second || (b.second == a.second && b.first < a.first);
            });
            
            iter_swap(max_iter, people.end() - 1);

            auto first = people.back();
            people.pop_back();

            // reconstruct the height by counting in result
            int predecessor = 0;
            for (auto& previous: result) {
                if (previous.first >= first.first) predecessor++;
            }
            result.push_back(make_pair(first.first, predecessor));

            // update predecessors, subtract first from
            for (auto& later: people) {
                if (first.first >= later.first) later.second--;
            }
        }
        return result;
    }
};

int main() {
    vector<pair<int,int>> input = {
            {7,0},
            {4,4},
            {7,1},
            {5,0},
            {6,1},
            {5,2}
    };

    Solution solution;
    auto output = solution.reconstructQueue(input);
    for (auto& p: output) {
        cout << p.first << "," << p.second << endl;
    }
}