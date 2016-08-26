#include <iostream>
#include <unordered_set>

using namespace std;

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        _maxNumber = maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (_freeNumbers.empty()) {
            if (_nextNewNumber == _maxNumber) {
                return -1;
            } else {
                return _nextNewNumber++;
            }
        } else {
            int i = *(_freeNumbers.begin());
            _freeNumbers.erase(i);
            return i;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (_freeNumbers.count(number)) {
            return true;
        } else {
            return number >= _nextNewNumber && number < _maxNumber;
        }
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= _maxNumber || number >= _nextNewNumber) {
            return;
        }
        _freeNumbers.insert(number);
    }
private:
    unordered_set<int> _freeNumbers;
    int _nextNewNumber = 0;
    int _maxNumber;
};

int main() {

    PhoneDirectory directory(3);
    int get1 = directory.get();
    cout << get1 << endl;
    int get2 = directory.get();
    cout << get2 << endl;
    cout << boolalpha << directory.check(3 - get1 - get2) << endl;
    int get3 = directory.get();
    cout << directory.check(get3) << endl;
    directory.release(2);
    cout << directory.check(2) << endl;
    cout << directory.get() << endl;
    cout << directory.get() << endl;
    return 0;
}