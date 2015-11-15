#include <iostream>

using namespace std;

int main() {

    float c;
    cin >> c;
    while (c != 0.00) {
        int i = 0;
        float k = 0;
        while (k < c) {
            i++;
            k += 1.0/(i+1);
        }
        cout << i << " " << "card(s)" << endl;
        cin >> c;
    }
}
