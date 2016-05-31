#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>

#define LEN_LOWER 3
#define LEN_UPPER 8

using namespace std;


vector<pair<pair<int, string>,string>> func() {

	vector<pair<pair<int, string>,string>>  data;

    string line;
    while(getline(cin,line))
    {
        stringstream lineStream(line);
        string name, text, cell;
        getline(lineStream, cell, ',');
        int i = stoi(cell);
        getline(lineStream, name, ',');
        getline(lineStream, text, ',');
        // if (text[0] == ' ')
        // 	text = text.substr(0);
        // cout << i << " " << name << " " << text << endl;
        data.push_back(make_pair(make_pair(i, name), text));
    }
    return data;
}

bool checkLeadingTo(const vector<string>& texts, int i, int j, unordered_map<int, unordered_map<int,bool>> & memoize) {

	if (memoize[i].count(j))
		return memoize[i][j];

	string s = texts[i];
	string t = texts[j];

	// cout << s << endl;
	// cout << t << endl;
	// cout << endl;

	int n = s.length();
	for (int k=LEN_LOWER; k<=LEN_UPPER; k++) {
		// cout << k << endl;
		if (s.length() < k || t.length() < k) break;
		int ii = 0;
		for (; ii<k; ii++) {
			// cout << n << endl;
			// cout << n-k+ii << endl;
			// cout << t[ii] << "," << s[n-k+ii] << endl;

			if (t[ii] != s[n-k+ii]) break;
		}
		if (ii == k) {
			memoize[i][j] = true;
			return true;
		}
	}
	memoize[i][j] = false;
	return false;
}

void dfs(const vector<string>& texts, vector<int>& path, vector<bool>& visited, int len, unordered_map<int, unordered_map<int,bool>>& leadsTo) {
	int n = visited.size();
	for (int j=0; j<n; j++) {
		if (visited[j]) continue;
		if (checkLeadingTo(texts, path[len], j, leadsTo)) {
			path.push_back(j);
			len += 1;
			visited[j] = 1;
			dfs(texts, path, visited, len, leadsTo);
			if (path.size() == n)
				return;
			visited[j] = 0;
			path.pop_back();
			len--;
		}
	}
}

vector<int> sort(const vector<string>& texts) {
	int n = texts.size();
	unordered_map<int, unordered_map<int,bool>> leadsTo;

	for (int i=0; i<n; i++) {
		int k = i;
		vector<int> path;
		vector<bool> visited(n);
		path.push_back(i);
		visited[i] = 1;
		dfs(texts, path, visited, 0, leadsTo);
		if (path.size() == n)
			return path;
	}
	return {};
}

int main() {

	auto data = func();
	vector<string> vs;
	for (auto& p: data) {
		vs.push_back(p.second);
	}

	auto vi = sort(vs);
	// cout << vi.size() << endl;
	for (int k = 0; k<vi.size(); k++) {
		int i = vi[k];
		for (int j=0; j<k; j++) {
			cout << "\t";
		}
		cout << "(" << data[i].first.first << "-" << data[i].first.second << ")" << data[i].second << endl;
	}
	// vector<string> vs = {"ABCDEF", "DEFGHI", "GHIJKL"};
	// auto vi = sort(vs);
	// for (int i : vi)
	// 	cout << i << " " << vs[i] << endl;
	// cout << checkLeadingTo("HHHHHHHABC", "ABCABCDEFG") << endl;

	return 0;
}