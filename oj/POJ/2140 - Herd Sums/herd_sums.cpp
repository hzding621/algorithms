#include <iostream>

using namespace std;

bool valid(int n, int k) {
    if (k % 2 == 0) {
        return n % k != 0 && (2 * n) % k == 0 &&
            (n / k - k / 2 + 1 > 0);
    } else {
        return n % k == 0 && (
            n / k - k / 2 > 0 );
    }
}

int main() {

    int n;
    cin >> n;
    int count = 0;
    for (int i=1; i<=n; i++) {
        if (valid(n, i))
            count++;
    }
    cout << count << endl;
    return 0;
}
