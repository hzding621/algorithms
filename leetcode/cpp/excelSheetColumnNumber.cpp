#include <iostream>
#include <string>
using namespace std;
int titleToNumber(string s) {
	int value = 0;
	for (int i=0; i<s.length(); i++) {
		char c = s[i];
		value = value * 26 + (c - 'A' + 1);
	}
	return value;
}
int main() {
	cout << titleToNumber("A") << endl;
	cout << titleToNumber("AA") << endl;
	cout << titleToNumber("AB") << endl;
	cout << titleToNumber("BA") << endl;
	cout << titleToNumber("ZZ") << endl;
	cout << titleToNumber("AAA") << endl;
}