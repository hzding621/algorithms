#include <unordered_map>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (_valueToIndex.count(val))
            return false;
        _valueToIndex[val] = _indexToValue.size();
        _indexToValue.push_back(val);
        return true;
    }    
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!_valueToIndex.count(val))
            return false;
        int releasedIndex = _valueToIndex[val];
        _indexToValue[releasedIndex] = _indexToValue.back();
        _valueToIndex[_indexToValue.back()] = releasedIndex;    
        _indexToValue.pop_back();
        _valueToIndex.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randomIndex = rand() % _indexToValue.size();
        return _indexToValue[randomIndex];
    }
private:
    unordered_map<int, int> _valueToIndex;;
    vector<int> _indexToValue;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {

}