/*
 * Complete the function below.
 */
#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;
using std::cout;
using std::endl;

int helper(string s, int start_index, map<char,int>& table) {
    if (s.size() - 1 < start_index) // length 0
        return 0;
    if (s.size() - 1 == start_index) // length 1
        return table[s[start_index]];
    char next = s[start_index+1];
    char head = s[start_index];
    if (table[head] < table[next]){
        int val = table[next] - table[head];
        return val + helper(s, start_index+2, table);
    } else {
        int count = 1;
        while (start_index+count < s.size() && s[start_index+count] == head) // find duplicate chars
            count++;
        int val = table[head] * count;
        return val + helper(s, start_index+count, table);
    }
}

int RomanToInt(string s) {
    map<char, int> table;
    table['I'] = 1;
    table['V'] = 5;
    table['X'] = 10;
    table['L'] = 50;
    table['C'] = 100;
    return helper(s, 0, table);
}

int main(){
	cout << RomanToInt("CXIX") << endl;
}