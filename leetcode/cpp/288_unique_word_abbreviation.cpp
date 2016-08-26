#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Corner cases:
// 1. duplicate in given dictionary input
// 2. query input is (not) present in dictionary

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto& s: dictionary) {
            if (_dictWords.count(s)) {
                continue;
            }
            _abbrCount[getAbbr(s)]++;
            _dictWords.insert(s);
        }
    }

    bool isUnique(string word) {
        if (_dictWords.count(word)) {
            return _abbrCount[getAbbr(word)] <= 1;
        } else {
            return _abbrCount[getAbbr(word)] == 0;
        }
    }
private:
    string getAbbr(const string& s) {
        if (s.length() <= 2) {
            return s;
        } else {
            return s.front() + to_string(s.length() - 2) + s.back();
        }
    }

    unordered_map<string, int> _abbrCount;
    unordered_set<string> _dictWords;
};

int main() {

    vector<string> v = {"deer", "door", "cake", "card"};
    ValidWordAbbr abbr(v);

    cout << boolalpha;
    cout << abbr.isUnique("dear") << endl;
    cout << abbr.isUnique("cart") << endl;
    cout << abbr.isUnique("cane") << endl;
    cout << abbr.isUnique("make") << endl;


    return 0;
}