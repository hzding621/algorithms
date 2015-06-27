#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        if (s.length()==0 || words.size()==0)
            return v;
        unordered_map<string,int> w;
        for (auto& ss: words)
            w[ss]++;

        int n = s.size(),
            m = words.size(),
            len = words[0].length();
        for (int i=0; i<len;i++) {
            int start = i;
            unordered_map<string,int> x;
            unordered_map<int,string> store;
            int cnt = 0;
            for (int j=i; j<=n-len; j+=len) {
                string sub = s.substr(j, len);
                if (w.count(sub)) {
                    if (x.count(sub) && x[sub] == w[sub]) {
                        while (store[start] != sub) {
                            x[store[start]]--;
                            cnt--;
                            start += len;
                        }
                        start += len;
                    }
                    else {
                        if (x.size() == 0)
                            start = j;
                        x[sub]++;
                        cnt++;
                    }
                    store[j] = sub;
                    if (cnt == m)
                        v.push_back(start);
                } else {
                    start = j;
                    x.clear();
                    cnt=0;
                }
            }
        }
        return v;
    }
};

void print(const vector<int>& v) {

    cout << "[";
    int i;
    for (i=0; i<v.size()-1; i++)
        cout << i << ",";
    cout << v[i] << "]" << endl;
}

int main() {

    Solution s;
    string str = "abababab";
    vector<string> v = {"a", "b", "a"};
    print(s.findSubstring(str, v));

    return 0;
}