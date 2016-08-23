#include <iostream>
#include <stack>
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

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        // hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger()) {
                    return true;
                }
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};

int main() {

    // vector<NestedInteger> v = {
    //     // NestedInteger(1),
    //     NestedInteger(vector<NestedInteger>{
    //         NestedInteger(2),
    //         NestedInteger(
    //             vector<NestedInteger>{
    //                 NestedInteger(3),
    //                 NestedInteger(4)
    //         })
    //     }),
    //     NestedInteger(5),
    //     NestedInteger(
    //         vector<NestedInteger>{
    //             NestedInteger(6),
    //             NestedInteger(7)
    //     }),
    //     NestedInteger(8)
    // };
    // NestedIterator it(v);
    // while (it.hasNext()) {
    //     cout << it.next() << endl;
    // }

    return 0;
}