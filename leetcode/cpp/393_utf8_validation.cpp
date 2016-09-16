#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:

    bool validUtf8(vector<int>& data) {
        int i = 0;
        while ((i = validate(data, i)) != -1 && i < data.size()) {

        }
        return i == data.size();
    }

    int validate(vector<int>& data, int i) {
        // State machine
        int leadingOnes = findNumberOfLeadingOnes(data[i]);
        if (leadingOnes == 0) return i+1;
        if (leadingOnes == 2) {
            if (i + 2 > data.size()) return -1;
            if (startsWithOneZero(data[i+1])) return i + 2;
        }
        if (leadingOnes == 3) {
            if (i + 3 > data.size()) return -1;
            if (startsWithOneZero(data[i+1]) && startsWithOneZero(data[i+2])) return i + 3;
        }
        if (leadingOnes == 4) {
            if (i + 4 > data.size()) return -1;
            if (startsWithOneZero(data[i+1]) && startsWithOneZero(data[i+2])
                && startsWithOneZero(data[i+3])) return i + 4;
        }
        return -1;
    }
    
private:
    int findNumberOfLeadingOnes(int k) {
        for (int shift = 7; shift >= 0; shift--) {
            if ((k >> shift) == 0) return 7 - shift;
            k ^= (1 << shift);
        }
        return 8;
    }

    bool startsWithOneZero(int k) {
        if ((k >> 7) == 0) return false;
        k ^= (1 << 7);
        return (k >> 6) == 0;
    }
};

int main() {

    vector<int> data = {115,100,102,231,154,132,13,10};

    Solution solution;
    cout << solution.validUtf8(data) << endl;

    return 0;
}