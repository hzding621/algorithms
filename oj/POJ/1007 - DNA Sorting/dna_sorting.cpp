#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


map<string, int> ranks;
vector<string> vs;

class Comparator {
public:
        Comparator(map<string,int>* ranks) {
            _map = ranks;
        }
        bool operator()(const string& s1, const string& s2) {
            return (*_map)[s1] < (*_map)[s2];
        }
private:
        map<string,int>* _map;
};

int score(string& s, int n) {
    int r = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (s[i] > s[j])
                r++;
        }
    }
    return r;
}

int main() {

    int length, n;
    cin >> length >> n;
    while (n > 0) {
        string next;
        cin >> next;
        ranks[next] = score(next, length);
        vs.push_back(next);
        n--;
    }
    Comparator comp(&ranks);
    stable_sort(vs.begin(), vs.end(), comp);
    for (int i = 0; i < vs.size(); i++) {
        cout << vs[i] << endl;
    }

    return 0;
}
