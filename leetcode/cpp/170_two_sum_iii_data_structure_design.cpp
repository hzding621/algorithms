#include <iostream>
#include <unordered_map>

using namespace std;

class TwoSum {
public:

    // Add the number to an internal data structure.
    void add(int number) {
        _intCount[number]++;        
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto& e: _intCount) {
            int storedValue = e.first, count = e.second, targetValue = value - storedValue;
            if ((storedValue == targetValue && count > 1) || (storedValue != targetValue && _intCount.count(targetValue))) {
                return true;
            } 
        }
        return false;
    }
private:
    unordered_map<int, int> _intCount;
};

int main() {

    TwoSum twoSum;
    twoSum.add(1);
    twoSum.add(3);
    twoSum.add(5);
    cout << twoSum.find(4) << endl;
    cout << twoSum.find(7) << endl;

    return 0;
}
