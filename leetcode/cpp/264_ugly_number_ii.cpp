#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        
        queue<int> multiplesOfTwo,
        			multiplesOfThree,
        			multiplesOfFive;
        int previousValue = 1;
        multiplesOfTwo.push(2);
        multiplesOfThree.push(3);
        multiplesOfFive.push(5);
        while (n > 1) {
        	int index = findSmallest(multiplesOfTwo.front(), multiplesOfThree.front(), multiplesOfFive.front());
        	int nextValue;
        	if (index == 0) {
				nextValue = multiplesOfTwo.front();
        		multiplesOfTwo.pop();
        	} else if (index == 1) {
        		nextValue = multiplesOfThree.front();
        		multiplesOfThree.pop();
        	} else {
        		nextValue = multiplesOfFive.front();
        		multiplesOfFive.pop();
        	}
        	if (nextValue > previousValue) {
    			n--;
    			previousValue = nextValue;
    			multiplesOfTwo.push(nextValue * 2);
    			multiplesOfThree.push(nextValue * 3);
    			multiplesOfFive.push(nextValue * 5);
    		}
        }
        return previousValue;
    }

private:
	int findSmallest(int a, int b, int c) {
		if (a <= b && a <= c)
			return 0;
		if (b <= a && b <= c)
			return 1;
		return 2;
	}
};

int main() {

	Solution sol;
	for (int i = 1; i <= 20; i++)
		cout << sol.nthUglyNumber(i) << endl;

	return 0;
}