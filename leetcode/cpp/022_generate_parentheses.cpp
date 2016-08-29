#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        dfs(result, s, n, 0);
        return result;
    }
private:
    void dfs(vector<string>& answer, string& builder, int open, int close) {
        if (open == 0 && close == 0) {
            answer.push_back(builder);
            return;
        }
        if (open > 0) {
            builder.push_back('(');
            dfs(answer, builder, open - 1, close + 1);
            builder.pop_back();
        }
        if (close > 0) {
            builder.push_back(')');
            dfs(answer, builder, open, close - 1);
            builder.pop_back();
        }
    }
};


int main() {
    
    Solution sol;
    vector<string> vs = sol.generateParenthesis(3);
    for (auto& s: vs) {
        cout << s << endl;
    }

}