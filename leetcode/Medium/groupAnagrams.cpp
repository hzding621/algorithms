class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        unordered_map<string, vector<string>> m;
        for (string& s: strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& e: m) {
            result.push_back(e.second);
        }
        return result;
    }
};