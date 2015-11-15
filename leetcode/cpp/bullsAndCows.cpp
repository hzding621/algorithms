#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string getHint(string secret, string guess) {
	unordered_map<char,int> s;
	for (char c : secret)
		s[c]++;
	int as = 0, bs = 0;
	for (int i=0; i<guess.size(); i++) {
		if (secret[i] == guess[i])
			as++;
		if (s[guess[i]] > 0) {
			bs++;
			s[guess[i]]--;
		}
	}
	bs = bs - as;
	return to_string(as)+"A"+to_string(bs)+"B";
}
int main() {
	return 0;
}