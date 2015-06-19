#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			unordered_set<char> hashtable;
			int max = 0;
			size_t i = 0, j = 0;
			for (; i<s.length(); i++) {
				if (hashtable.find(s[i]) == hashtable.end())
					hashtable.insert(s[i]);
				else {
					max = std::max(max, (int) hashtable.size());
					for (; s[j]!=s[i]; j++ )
						hashtable.erase(hashtable.find(s[j]));
					j++;
				}
			}
			max = std::max(max, (int) hashtable.size());
			return max;
		} 
};

int main() {

	Solution s;
	string str = "abcabcbbacdefff";
	cout << s.lengthOfLongestSubstring(str) << endl;

}
