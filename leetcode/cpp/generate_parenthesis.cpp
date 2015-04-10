#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>

using std::vector;
using std::string;
using std::unordered_set;
using std::cout;
using std::endl;


vector<string> generate_parenthesis(int n) {
	unordered_set<string> ret;
	ret.insert("");
	for (int i=0; i<n; i++) {

		unordered_set<string> next;
		for (auto& s: ret) {
			for (int i=0; i<s.length(); i++) {
				if (s[i] == '(') {
					string new_string = s.substr(0, i+1) + "()" + s.substr(i+1, s.length()-1-i);
					next.insert(new_string);
				}
			}
			next.insert("()"+s);
			next.insert(s+"()");
		}
		ret = std::move(next);

	}
	vector<string> v;
	for (auto& s: ret) {
		v.push_back(s);
	}
	return v;
}

int main(){

	vector<string> three = generate_parenthesis(3);
	for (auto& s: three) {
		cout << s << endl;
	}
	return 0;
}