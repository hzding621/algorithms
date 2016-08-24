#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <cassert>

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger() {
        _isInteger = false;
    }
 
    // Constructor initializes a single integer.
    NestedInteger(int value) {
        _isInteger = true;
        _v = value;
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list
    bool isInteger() const {
        return _isInteger;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return _v;
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        _v = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        _l.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return _l;
    }
private:

    bool _isInteger;
    int _v;
    vector<NestedInteger> _l;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        istringstream iss(s);
        if (s[0] != '[') {
            int i;
            iss >> i;
            return NestedInteger(i);
        } else {
            return extractList(iss);
        }
    }
private:

    NestedInteger extractList(istringstream& iss) {
        if (iss.peek() != '[') {
            throw invalid_argument("Does not start with [");
        }
        NestedInteger rootList;
        iss.ignore(); // skip '['
        while (iss.peek() != ']') {
            if (iss.peek() == '[') {
                rootList.add(extractList(iss));
            } else {
                int i;
                iss >> i;
                rootList.add(NestedInteger(i));
            }
            if (iss.peek() == ',') {
                iss.get();
            }
        }
        iss.ignore(); // skip ']'
        return rootList;
    }
};

int main() {

    string s = "[123,[456,[789]]]";
    Solution sol;
    NestedInteger ni = sol.deserialize(s);
    assert(!ni.isInteger());
    auto vni = ni.getList();
    assert(vni.size() == 2);
    assert(vni[1].getList().size()==2);
    cout << (vni[1].getList()[1].getList()[0].getInteger()) << endl;

    return 0;
}