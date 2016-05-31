#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cout << "Scenario #" << i << ':' << endl;
        int k;
        cin >> k;
        for (int j=1; j<=(2*k+1); j++) {
            cout << "slice #" << j << ':' << endl;
            int center = abs(j-k-1);
            for (int ii=1; ii<=(2*k+1); ii++) {
                for (int jj=1; jj<=(2*k+1); jj++) {
                    int dist = abs(ii-k-1) + abs(jj-k-1);
                    if (center + dist <= k)
                        cout << center+dist;
                    else
                        cout << '.';
                }
                cout << endl;
            }
        }
        cout << endl;
    }
}
