#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <set>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // first pass, find leftBound and rightBound
        // second pass from lower to upper, split into enter and exit events
        // - check whether boxes intersect
        // - check whether boxes together cover all from leftBound to rightBound;

        //     |  |
        // 3 --+--+--
        //     |  |
        // 1 --+--+--
        //     |  |
        //     0  2

        using Event = pair<int, vector<int>>;
        using LR = pair<int,int>;

        int leftBound = INT_MAX, rightBound = INT_MIN;
        vector<Event> events;
        for (auto& coordinates: rectangles) {
            leftBound = min(leftBound, coordinates[0]);
            rightBound = max(rightBound, coordinates[2]);

            // create two events for one box,
            // time = lowerEdge (enter) / upperEdge (exit)
            events.push_back(make_pair(coordinates[1], coordinates));
            events.push_back(make_pair(coordinates[3], coordinates));
        }

        // sort events based on time
        sort(events.begin(), events.end(), 
            [](const Event& i, const Event& j) {
                if (i.first != j.first) return i.first < j.first;
                if (i.second[1] != j.second[1]) return i.second[1] < j.second[1]; // exit goes first
                return i.second[0] < j.second[0];
            });

        auto comp = [](const LR& i, const LR& j) {
            return i.second <= j.first;
        };
        set<pair<int,int>, decltype(comp)> activeLRIntervals(comp);
        int coveredLeftRight = 0;

        int i = 0;
        while (i < events.size()) {
            int time = events[i].first;
            while (i < events.size() && events[i].first == time) {
                auto ev = events[i++];
                auto interval = make_pair(ev.second[0], ev.second[2]);
                if (ev.first == ev.second[1]) {
                    // enter event
                    if (!(activeLRIntervals.insert(interval).second)) {
                        // interval intersected
                        // cout << "intersection" << endl;
                        return false;
                    }
                    coveredLeftRight += interval.second - interval.first;
                } else {
                    activeLRIntervals.erase(interval);
                    coveredLeftRight -= interval.second - interval.first;
                }
            }

            if (i < events.size()) {
                if (activeLRIntervals.empty()) {
                    // vertical gap;
                    // cout << "vertical gap" << endl;
                    return false;
                }
                if (coveredLeftRight != rightBound - leftBound) {
                    // horizontal gap
                    // cout << "horizontal gap" << endl;
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    vector<vector<int>> example1 = {
        {1,1,3,3},
        {3,1,4,2},
        {3,2,4,4},
        {1,3,2,4},
        {2,3,3,4}
    };

    vector<vector<int>> example2 = {
        {1,1,2,3},
        {1,3,2,4},
        {3,1,4,2},
        {3,2,4,4}
    };

    vector<vector<int>> example3 = {
        {1,1,3,3},
        {3,1,4,2},
        {1,3,2,4},
        {3,2,4,4}
    };

    vector<vector<int>> example4 = {
        {1,1,3,3},
        {3,1,4,2},
        {1,3,2,4},
        {2,2,4,4}
    };

    Solution sol;
    cout << boolalpha;
    // cout << sol.isRectangleCover(example1) << endl;
    // cout << sol.isRectangleCover(example2) << endl;
    // cout << sol.isRectangleCover(example3) << endl;
    // cout << sol.isRectangleCover(example4) << endl;

    return 0;
}