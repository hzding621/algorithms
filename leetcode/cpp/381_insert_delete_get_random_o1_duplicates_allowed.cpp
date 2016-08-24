#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool alreadyContains = _valueToIndices.count(val);
        _valueToIndices[val].insert(_indexToValue.size());
        _indexToValue.push_back(val);
        return !alreadyContains;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool contains = _valueToIndices.count(val);
        if (!contains) {
            return contains;
        }
        if (_indexToValue.size() == 1) {
            _indexToValue.clear();
            _valueToIndices.clear();
            return contains;
        }
        int someIndex = *(_valueToIndices[val].begin());
        int valueToMove = _indexToValue.back();
        _valueToIndices[val].erase(someIndex);
        _indexToValue.pop_back();
        if (someIndex < _indexToValue.size()) {
            // swap the value at back to the removed value's position
            // if the removed value's position is not back
            _indexToValue[someIndex] = valueToMove;
            _valueToIndices[valueToMove].erase(_indexToValue.size());
            _valueToIndices[valueToMove].insert(someIndex);
        }
        if (_valueToIndices[val].empty()) {
            _valueToIndices.erase(val);
        }
        return contains;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return _indexToValue[rand() % _indexToValue.size()];
    }

private:
    vector<int> _indexToValue;
    unordered_map<int, unordered_set<int>> _valueToIndices;
};

int main() {

    RandomizedCollection collection;
    // collection.insert(0);
    // collection.insert(0);
    // collection.insert(1);
    // vector<int> counts = {0, 0};
    // for (int i = 0; i < 1000; i++) {
    //     counts[collection.getRandom()]++;
    // }
    // cout << "counts[0]=" << counts[0] << endl;
    // cout << "counts[1]=" << counts[1] << endl;
    // collection.remove(0);
    // counts[0] = counts[1] = 0;
    // for (int i = 0; i < 1000; i++) {
    //     counts[collection.getRandom()]++;
    // }
    // cout << "counts[0]=" << counts[0] << endl;
    // cout << "counts[1]=" << counts[1] << endl;
    cout << boolalpha << collection.insert(1) << endl;
    cout << collection.insert(1) << endl;
    cout << collection.insert(2) << endl;
    cout << collection.insert(1) << endl;
    cout << collection.insert(2) << endl;
    cout << collection.insert(2) << endl;
    cout << collection.remove(1) << endl;
    cout << collection.remove(2) << endl;
    cout << collection.remove(2) << endl;
    cout << collection.remove(2) << noboolalpha << endl;

    cout << collection.getRandom() << endl;
    cout << collection.getRandom() << endl;
    cout << collection.getRandom() << endl;
    cout << collection.getRandom() << endl;
    cout << collection.getRandom() << endl;
    cout << collection.getRandom() << endl;

    return 0;
}