#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<pair<bool, string>> tokens;
        string s;
        for (char c: input) {
        	if (isInt(c)) {
        		s += c;
        	} else {
        		tokens.push_back(make_pair(1, s));
        		tokens.push_back(make_pair(0, string(1, c)));
        		s = "";
        	}
        }
        tokens.push_back(make_pair(1,s));
        return execute(tokens, 0, tokens.size() - 1);
    }

    vector<int> execute(vector<pair<bool, string>>& input, int startIndex, int endIndex) {
    	if (startIndex == endIndex) {
    		int num = stoi(input[startIndex].second);
    		return vector<int>{num};
    	}

		vector<int> answers;
    	for (int i = startIndex; i <= endIndex; i++) {
    		if (!input[i].first) {
    			char c = input[i].second[0];
    			vector<int> leftAnswers = execute(input, startIndex, i-1);
    			vector<int> rightAnswers = execute(input, i+1, endIndex);
    			
    			for (int a: leftAnswers) {
    				for (int b: rightAnswers) {
    					if (c == '+') {
    						answers.push_back(a + b);
    					} else if (c == '-') {
    						answers.push_back(a - b);
    					} else if (c == '*') {
    						answers.push_back(a * b);
    					}
    				}
    			}
    		}
    	}
    	sort(answers.begin(), answers.end());
    	return answers;
    }


private:
	bool isInt(char c) {
		return c >= '0' && c <= '9';
 	}
};

int main() {
	Solution sol;
	string s = "2*3-4*5";
	vector<int> v = sol.diffWaysToCompute(s);
	for (int i: v) {
		cout << i << " ";
	}
	cout << endl;
}