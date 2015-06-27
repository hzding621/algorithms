#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void append(int& n, char c) {
        n <<= 2;
        if (c == 'C')
            n |= 1;
        else if (c == 'G')
            n |= 2;
        else if (c == 'T')
            n |= 3;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        int n = 0;
        if (s.length() <= 10)
            return ret;
        unordered_map<int, int> counts;

        for (int k=0; k<=9; k++) {
            append(n, s[k]);
        }
        counts[n]++;
        for (int i=10; i<s.length(); i++) {
            int mask = (1 << 18) - 1;
            n &= mask;
            append(n, s[i]);
            counts[n]++;
        }
        for (const auto& t: counts) {
            if (t.second >= 2)
                ret.push_back(recover(t.first));
        }
        return ret;
    }

    string recover(int n) {
        string s;
        int i = 10;
        while (i-- > 0) {
            int lsb = n & 3;
            if (lsb == 0)
                s.push_back('A');
            else if (lsb == 1)
                s.push_back('C');
            else if (lsb == 2)
                s.push_back('G');
            else
                s.push_back('T');
            n >>= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

void print(const vector<string>& v) {
	for (auto& s: v)
		cout << s << endl;
}

int main() {

	Solution sol;
	print(sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
}