#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {

	int values[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	string strs[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

public:
    string intToRoman(int num) {
        stringstream ss;
        for (int i=0; i<13; i++) {
        	while(num >= values[i]) {
        		num -= values[i];
        		ss << strs[i];
        	}
        }
        return ss.str();
    }
};

int main() {
	Solution s;
	cout << s.intToRoman(120) << endl;
}
