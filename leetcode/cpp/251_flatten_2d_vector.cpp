#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d)
    : _vec2d(vec2d) {
        _rowIter = _vec2d.begin();  
        if (_rowIter != _vec2d.end()) {
            _columnIter = _rowIter->begin();
        }
    }

    int next() {
        return *_columnIter++;
    }

    bool hasNext() {
        while (_rowIter != _vec2d.end() && _columnIter == _rowIter->end()) {
            _rowIter++;
            _columnIter = _rowIter->begin();
        }
        return _rowIter != _vec2d.end();
    }
private:
    vector<vector<int>>& _vec2d;
    vector<vector<int>>::iterator _rowIter;
    vector<int>::iterator _columnIter;
};


int main() {

    vector<vector<int>> v = {
        {1,2},
        {3},
        {4,5,6}
    };
    Vector2D vec2d(v);
    while (vec2d.hasNext()) {
        cout << vec2d.next() << endl;
    }

    return 0;
}