#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> split(string s, string delim) {
	char c = delim[0];
	for (int i=1; i<delim.length(); i++)
		replace(s.begin(), s.end(), delim[i], c);
	istringstream iss(s);
	string tok;
	vector<string> result;
	while (getline(iss, tok, c))
		result.push_back(tok);
	return result;
}

int main() {

	string s = "John likes apple.";
	auto v = split(s, ". ");
	for (auto ss: v)
		cout << ss << endl;
}