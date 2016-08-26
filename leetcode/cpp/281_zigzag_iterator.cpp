#include <iostream>
#include <vector>

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) 
        : _v1(v1), _v2(v2) {
            _firstIsNext = v1.size();
        }

    int next() {
        int r = _firstIsNext ? _v1[_i1++] : _v2[_i2++];
        _firstIsNext = !_firstIsNext;
        if (_firstIsNext && _i1 == _v1.size()) {
            _firstIsNext = !_firstIsNext;
        } else if (!_firstIsNext && _i2 == _v2.size()) {
            _firstIsNext = !_firstIsNext;
        }
        return r;
    }

    bool hasNext() {
        return _i1 < _v1.size() || _i2 < _v2.size();
    }
private:
    int _i1 = 0, _i2 = 0;
    bool _firstIsNext;
    vector<int> _v1, _v2;
};

int main() {

    vector<int> v1 = {};
    vector<int> v2 = {2};
    ZigzagIterator iter(v1, v2);
    while (iter.hasNext()) {
        cout << iter.next() << endl;
    }
}
