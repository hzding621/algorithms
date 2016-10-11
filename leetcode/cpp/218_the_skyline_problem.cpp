#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set<tuple<int,int,int>> uniqueVert;
        for (vector<int>& triple: buildings) {
        	int l = triple[0], r = triple[1], h = triple[2];
        	auto left_mark = make_tuple(l, -h, -1);
        	auto right_mark = make_tuple(r, h, l);
        	uniqueVert.insert(left_mark);
        	uniqueVert.insert(right_mark);
        }
        vector<tuple<int,int,int>> sortedVert;
        sortedVert.assign(uniqueVert.begin(), uniqueVert.end());

        map<int, int> activeSet; // height -> count
        vector<pair<int,int>> skylinePoints;
        for (int i=0; i<sortedVert.size(); i++) {
        	auto& mark = sortedVert[i];
        	int pos = get<0>(mark), previousPos = get<2>(mark);
        	if (previousPos < 0) {
        		int h = -get<1>(mark);
        		if (activeSet.empty() || activeSet.rbegin()->first < h) {
        			skylinePoints.push_back(make_pair(pos, h));
        		}
        		activeSet[h]++;
        	} else {
        		int h = get<1>(mark);
        		activeSet[h]--;

        		if (activeSet[h] == 0) {
        			activeSet.erase(h);
        		}
        		if (activeSet.empty()) {
        			skylinePoints.push_back(make_pair(pos,0));
        		} else {
        			if (activeSet.rbegin()->first < h) {
        				skylinePoints.push_back(make_pair(pos, activeSet.rbegin()->first));
        			}
        		}
        	}
        }
        return skylinePoints;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> b;

	/*{
		//[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] 
		b.push_back(vector<int>{2,9,10});
		b.push_back(vector<int>{3,7,15});
		b.push_back(vector<int>{5,12,12});
		b.push_back(vector<int>{15,20,10});
		b.push_back(vector<int>{19,24,8});
	}*/

	/*{
		//[[0,2,3],[2,5,3]]
		b.push_back(vector<int>{0,2,3});
		b.push_back(vector<int>{2,5,3});
	}*/

	/*{
		// [[1,2,1],[1,2,2],[1,2,3]]
		b.push_back(vector<int>{1,2,1});
		b.push_back(vector<int>{1,2,2});
		b.push_back(vector<int>{1,2,3});
	}*/

	/*{
		// [[1,3,4],[1,3,4],[1,3,4]]
		b.push_back(vector<int>{1,3,4});
		b.push_back(vector<int>{1,3,4});
		b.push_back(vector<int>{1,3,4});
	}*/

	/*{ // [[4,10,10],[5,10,9],[6,10,8],[7,10,7],[8,10,6],[9,10,5]]
		b.push_back(vector<int>{4,10,10});
		b.push_back(vector<int>{5,10,9});
		b.push_back(vector<int>{6,10,8});
		b.push_back(vector<int>{7,10,7});
		b.push_back(vector<int>{8,10,6});
		b.push_back(vector<int>{9,10,5});
	}*/
	{
		b.push_back(vector<int>{1,2,2});
		b.push_back(vector<int>{2,3,1});
	}

	auto res = sol.getSkyline(b);
	for (auto& p: res) {
		cout << p.first << " " << p.second << endl;
	}

}