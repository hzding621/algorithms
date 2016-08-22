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
        _input = nestedList;
        pullFromInput();
    }

    int next() {
        if (_nextInputIsSingleton) {
            int result = _input[_indexIntoInput++].getInteger();
            pullFromInput();
            return result;
        }
        int result = _stackNi.top().getList()[_stackIndex.top()].getInteger();
        incrementStackTop();
        seek();
        return result;
    }

    bool hasNext() {
        return _hasNext;
    }
private:

    vector<NestedInteger> _input;
    int _indexIntoInput = 0;
    bool _nextInputIsSingleton = false;

    bool _hasNext = true;
    stack<NestedInteger> _stackNi;
    stack<int> _stackIndex;

    void seek() {
        int hasPulledFromInput = false;
        while (true) {
            while (_stackIndex.top() == _stackNi.top().getList().size()) {
                _stackIndex.pop();
                _stackNi.pop();
                if (_stackNi.empty()) {
                    pullFromInput();
                    hasPulledFromInput = true;
                    break;
                }
                incrementStackTop();
            }
            if (!hasPulledFromInput && !(_stackNi.top().getList()[_stackIndex.top()].isInteger())) {
                _stackNi.push(_stackNi.top().getList()[_stackIndex.top()]);
                _stackIndex.push(0);
            } else {
                break;
            }
        }
       
    }

    void incrementStackTop() {
        int i = _stackIndex.top();
        _stackIndex.pop();
        _stackIndex.push(i+1);
    }

    void pullFromInput() {

        if (_indexIntoInput == _input.size()) {
            _hasNext = false;
            return;
        }

        if (_input[_indexIntoInput].isInteger()) {
            _nextInputIsSingleton = true;
        } else {
            _stackNi.push(_input[_indexIntoInput++]);
            _stackIndex.push(0);
            _nextInputIsSingleton = false;
            seek();
        }
    }
};

int main() {

    vector<NestedInteger> v = {
        NestedInteger(1),
        NestedInteger(vector<NestedInteger>{
            // NestedInteger(2),
            NestedInteger(
                vector<NestedInteger>{
                    // NestedInteger(3),
                    // NestedInteger(4)
            })
        }),
        NestedInteger(5),
        NestedInteger(
            vector<NestedInteger>{
                // NestedInteger(6),
                // NestedInteger(7)
        }),
        NestedInteger(8)
    };
    NestedIterator it(v);
    while (it.hasNext()) {
        cout << it.next() << endl;
    }

    return 0;
}