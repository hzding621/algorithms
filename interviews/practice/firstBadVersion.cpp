#include <iostream>
using namespace std;

int badVersion = 1702766719;

bool isBadVersion(int version) {
	return version >= badVersion;
}
int firstBadVersion(int n) {
	long long i = 1, j = n;
    while (true) {
        long long m = (i + j) / 2;
        if (isBadVersion(m) && (m == 1 || !isBadVersion(m-1))) return m;
        else if (isBadVersion(m)) j = m;
        else i = m+1;
    }
}
int main() {
	firstBadVersion(2126753390);
}