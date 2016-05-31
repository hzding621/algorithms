#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

string sentenceReverse(string s) {
	replace(s.begin(), s.end(), '\n',' ');
	bool period = false;
	if (s.back() == '.') {
		s.pop_back();
		period = true;
	}
	istringstream iss(s);
	string tok;
	vector<string> v;
	while (getline(iss, tok, ' ')) {
		v.push_back(tok);
	}
	stringstream output;
	for (auto it=v.rbegin(); it != v.rend(); it++) {
		output << *it << " ";
	}
	string result = output.str();
	if (result.back() == ' ')
		result.pop_back();
	if (period)
		result += '.';
	return result;
}


int main() {
	cout << sentenceReverse("This is a sentence.") << endl;
	cout << sentenceReverse("Hi.") << endl;
	cout << sentenceReverse("") << endl;
	cout << sentenceReverse(".") << endl;
	cout << sentenceReverse("This is a newline\n.") << endl;

}