#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

int findMaxHittingPoint(vector<pair<int,int>>& intervals) {
	vector<pair<int,bool>> endpts;
	for (auto& p: intervals) {
		endpts.push_back(make_pair(p.first, 0));
		endpts.push_back(make_pair(p.second, 1));
	}
	sort(endpts.begin(), endpts.end());

	pair<int,int> maxPoint;
	int current = 0;
	for (int i=0; i<endpts.size(); i++) {
		if (endpts[i].second == 0) {
			current++;
			if (maxPoint.first < current)  {
				maxPoint = make_pair(current, endpts[i].first);
 			}
		} else {
			current--;
		}
	}
	return maxPoint.second;
}

int main() {

	vector<pair<int,int>> v;
	v.push_back(make_pair(2,3));
	v.push_back(make_pair(3,5));
	v.push_back(make_pair(4,5));
	v.push_back(make_pair(1,5));
	v.push_back(make_pair(1,2));
	cout << findMaxHittingPoint(v) << endl;

	return 0;
}