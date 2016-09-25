#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
    bool isInteger() const {
        return _isInteger;
    }

    int getInteger() const {
        return _int;
    }

    const vector<NestedInteger> &getList() const {
        return _list;
    }

    NestedInteger(int i) {
        _isInteger = true;
        _int = i;
    }

    NestedInteger(const vector<NestedInteger>& list) {
        _isInteger = false;
        _list = list;
    }
private:
    bool _isInteger;
    int _int;
    vector<NestedInteger> _list;
};

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;
        for (const auto& ni: nestedList) {
            sum += dfs(ni, 1);
        }
        return sum;
    }

private:
    int dfs(const NestedInteger& ni, int depth) {
        if (ni.isInteger()) {
            return ni.getInteger() * depth;
        } else {
            int sum = 0;
            for (const auto& child: ni.getList()) {
                sum += dfs(child, depth + 1);
            }
            return sum;
        }
    }
};

int main() {

    return 0;
}