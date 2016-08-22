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
    NestedIterator(vector<NestedInteger> &nestedList) 
    : _input(nestedList) { 
        populateStackIfNecessary();
    }

    int next() {
        int result;
        if (currentInputIsSingleton()) {
            result = _input[_indexIntoInput++].getInteger();
            populateStackIfNecessary();
            return result;
        } else {
            result = getCurrentNestInt().getInteger();
            incrementStackTop();
            seekSingleton();
            return result;
        }   
    }

    bool hasNext() {
        return _hasNext;
    }
private:

    bool _hasNext = true;
    const vector<NestedInteger>& _input;
    int _indexIntoInput = 0;
    stack<NestedInteger> _stackOfInts;
    stack<int> _stackOfActiveIndices;

    bool currentInputIsSingleton() {
        return _input[_indexIntoInput].isInteger();
    }

    void seekSingleton() {
        while (true) {
            while (_stackOfActiveIndices.top() == _stackOfInts.top().getList().size()) {
                _stackOfActiveIndices.pop();
                _stackOfInts.pop();
                if (_stackOfInts.empty()) {
                    // advance to next input
                    _indexIntoInput++;
                    populateStackIfNecessary();
                    return;
                }
                incrementStackTop();
            }
            if (getCurrentNestInt().isInteger())
                return;

            _stackOfInts.push(getCurrentNestInt());
            _stackOfActiveIndices.push(0);
        }
       
    }

    void incrementStackTop() {
        int i = _stackOfActiveIndices.top();
        _stackOfActiveIndices.pop();
        _stackOfActiveIndices.push(i+1);
    }

    void populateStackIfNecessary() {

        if (_indexIntoInput == _input.size()) {
            _hasNext = false;
            return;
        }

        if (!currentInputIsSingleton()) {
            _stackOfInts.push(_input[_indexIntoInput]);
            _stackOfActiveIndices.push(0);
            seekSingleton();
        }
    }

    NestedInteger getCurrentNestInt() {
        return _stackOfInts.top().getList()[_stackOfActiveIndices.top()];
    }
};

int main() {

    vector<NestedInteger> v = {
        // NestedInteger(1),
        NestedInteger(vector<NestedInteger>{
            NestedInteger(2),
            NestedInteger(
                vector<NestedInteger>{
                    NestedInteger(3),
                    NestedInteger(4)
            })
        }),
        NestedInteger(5),
        NestedInteger(
            vector<NestedInteger>{
                NestedInteger(6),
                NestedInteger(7)
        }),
        NestedInteger(8)
    };
    NestedIterator it(v);
    while (it.hasNext()) {
        cout << it.next() << endl;
    }

    return 0;
}