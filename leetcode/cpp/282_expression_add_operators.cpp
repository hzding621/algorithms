#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
    	if (num.size() == 0)
    		return {};
        vector<string> answer;
        DFS(answer, num, target, "", 0, 0, 1, 0);
        return answer;
    }

private:

	void DFS(vector<string>& answer, const string& num, int target, 
			 string path, int pos, int accumulatedValue, int multiplier, long currentToken) {
		currentToken = currentToken * 10 + (num[pos] - '0');
		path += num[pos];
		if (currentToken > INT_MAX) return;
		if (pos == num.size() - 1) {
			if (accumulatedValue + currentToken * multiplier == target) {	
				answer.push_back(path);
			}
			return;
		}		
		if (currentToken) {
			// Prevent appending to token "0"
			DFS(answer, num, target, path, pos+1, accumulatedValue, multiplier, currentToken);
		}
		DFS(answer, num, target, path + "+", pos+1, accumulatedValue + multiplier * currentToken, 1, 0);
		DFS(answer, num, target, path + "-", pos+1, accumulatedValue + multiplier * currentToken, -1, 0);
		DFS(answer, num, target, path + "*", pos+1, accumulatedValue, multiplier * currentToken, 0);
	}
};

int main() {
	Solution sol;
	auto vs = sol.addOperators("123", 6);
	for (auto& s: vs)
		cout << s << endl;
}