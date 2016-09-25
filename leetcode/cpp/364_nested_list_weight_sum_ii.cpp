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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 0;
        findDepth(depth, nestedList, 1);
        return dfs(nestedList, 0, depth);
    }

private:

    void findDepth(int& depth, const vector<NestedInteger>& nestedList, int curDepth) {
        for (const auto& child: nestedList) {
            if (child.isInteger()) {
                depth = max(depth, curDepth);
            } else {
                findDepth(depth, child.getList(), curDepth + 1);
            }
        }
    }

    int dfs(const vector<NestedInteger>& nestedList, int curDepth, int depth) {
        int sum = 0;
        for (const auto& child: nestedList) {
            if (child.isInteger()) {
                sum += child.getInteger() * (depth - curDepth);
            } else {
                sum += dfs(child.getList(), curDepth + 1, depth);
            }
        }
        return sum;
    }
};

int main() {

    Solution solution;
    vector<NestedInteger> nestedList = vector<NestedInteger>{
            NestedInteger{
                    vector<NestedInteger>{
                            NestedInteger{1},
                            NestedInteger{1}
                    }
            },
            NestedInteger{2},
            NestedInteger{
                    vector<NestedInteger>{
                            NestedInteger{1},
                            NestedInteger{1}
                    }
            },
    };
    cout << solution.depthSumInverse(nestedList) << " expected: 8" << endl;

    return 0;
}