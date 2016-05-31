#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;


bool stringCompare(string& s1, string& s2) {
	return s1.length() > s2.length();
}

int stringChain(unordered_set<string>& dict) {
	vector<string> v;
	for (const string& s : dict)
		v.push_back(s);
	sort(v.begin(), v.end(), stringCompare);
	int n = dict.size();
	unordered_map<string, bool> vst;
	int maxLength = 1;
	for (int i=0; i<n; i++) {
		if (!vst[v[i]]) {
			queue<pair<string,int>> qu;
			qu.push(make_pair(v[i], 1));
			vst[v[i]] = true;
			while (qu.size() ){
				auto p = qu.front();
				qu.pop();
				maxLength = max(maxLength, p.second);
				for (int j=0; j<p.first.length(); j++) {
					string removed = p.first.substr(0, j) + p.first.substr(j+1);
					if (dict.count(removed) && !vst[removed]) {
						qu.push(make_pair(removed, p.second+1));
						vst[removed] = true;
					}
				}
			}
		}
	}
	return maxLength;
}

int main() {
	unordered_set<string> s = {"a","b","ba","bca","bda","bdca","bdaca"};
	cout << stringChain(s) << endl;

}