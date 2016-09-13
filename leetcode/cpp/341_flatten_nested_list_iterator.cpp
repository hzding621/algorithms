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
        it = new ListIterator(nestedList);
    }

    int next() {
        if (!it->hasNext()) {
            throw out_of_range("Iterator has reached end!");
        }
        return it->next();
    }

    bool hasNext() {
        return it->hasNext();
    }
private:
    class RecursiveIterator {
    public:
        virtual bool hasNext() = 0;
        virtual int next() = 0;
    };

    class IntIterator : public RecursiveIterator {
    public:
        IntIterator(int i) : _i(i){}

        int next() {
            if (!hasNext()) {
                throw out_of_range("Iterator has reached end!");
            }
            _hasEnd = true;
            return _i;
        }

        bool hasNext() {
            return !_hasEnd;
        }
    private:
        int _i;
        bool _hasEnd = false;
    };

    class ListIterator : public RecursiveIterator {
    public:
        ListIterator(const vector<NestedInteger>& list) {
            for (const auto& ni: list) {
                if (ni.isInteger()) {
                    _itList.push_back(new IntIterator(ni.getInteger()));
                } else {
                    _itList.push_back(new ListIterator(ni.getList()));
                }
            }
        }

        int next() {
            if (!hasNext()) {
                throw out_of_range("Iterator has reached end!");
            }
            return _itList[_i]->next();
        }

        bool hasNext() {
            while (_i < _itList.size() && !(_itList[_i]->hasNext())) {
                _i++;
            }
            return _i < _itList.size();
        }

    private:
        vector<RecursiveIterator*> _itList;
        int _i = 0;
    };
    
    RecursiveIterator *it;
};

int main() {

    vector<NestedInteger> v = {
        NestedInteger(1),
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