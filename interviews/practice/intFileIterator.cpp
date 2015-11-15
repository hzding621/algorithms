#include <iostream>
#include <vector>
#include <string>

using namespace std;

class IntFileIterator {
private:
	vector<int> _ints;
	int _nextIndex = 0;
public:
	IntFileIterator(vector<int> v) : _ints(v) {}
	bool hasNext() {
		return _nextIndex < _ints.size();
	}
	int next() {
		return _ints.at(_nextIndex++);
	}
};

class FileCompare {
public:
	bool isDistanceZeroOrOne(IntFileIterator a, IntFileIterator b) {
		int preA, preB, curA = 0, curB = 0;
		int modified = false;
		int replaceFail = false, insertFail = false, deleteFail = false;
		while (a.hasNext() && b.hasNext()) {
			preA = curA, preB = curB;
			curA = a.next(), curB = b.next();
			if (!modified) {
				if (curA != curB) modified = true;
			} else {
				if (curA != curB) replaceFail = true;
				if (curA != preB) insertFail = true;
				if (curB != preA) deleteFail = true;
				if (replaceFail && insertFail && deleteFail) return false;
			}
		}
		int aleft = 0, bleft = 0;
		while (a.hasNext()) {
			curA = a.next(); 
			aleft++;
		}
		while (b.hasNext()) {
			curB = b.next(); 
			bleft++;
		}
		if (!modified) 
			return aleft <= 1 && bleft <= 1;
		if (!replaceFail && aleft == 0 && bleft == 0)
			return true;
		if (!insertFail && aleft == 1 && curA == curB)
			return true;
		if (!deleteFail && bleft == 1 && curA == curB)
			return true;
		return false;
	}
};

int main() {

	FileCompare f;
	IntFileIterator i1(vector<int>{2,3,5}),
					i2(vector<int>{3,5});
	cout << boolalpha << f.isDistanceZeroOrOne(i1,i2) << endl;

	return 0;
}