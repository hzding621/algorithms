#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        return search(s, 0, s.length() - 1);
    }
private:

    string search(string& s, int start, int end) {
        if (start > end) return "";
        string result;
        int i = start;
        while (i <= end && !isdigit(s[i])) {
            result.push_back(s[i]);
            i++;
        }
        if (i > end) {
            return result;
        }
        int j = i;
        while (j <= end && isdigit(s[j])) {
            // parse number
            j++;
        }
        int times = stoi(s.substr(i, j));
        int k = j + 1;
        int count = 1;
        while (k <= end && count) {
            // find matching ']'
            if (s[k] == '[') count++;
            else if (s[k] == ']') count--;
            k++;
        }
        k -= 1;
        string inside = search(s, j + 1, k - 1);
        while (times > 0) {
            result += inside;
            times--;
        }
        result += search(s, k + 1, end);
        return result;
    }
};

int main() {

    vector<string> tests = {
            "3[a]2[bc]",
            "3[a2[c]]",
            "2[abc]3[cd]ef",
            "2[a2[b2[c]]]",
            "2[]",
            "2[]3[a]"
    };

    Solution solution;
    for (auto& s: tests) {
        cout << solution.decodeString(s) << endl;
    }

    return 0;
}