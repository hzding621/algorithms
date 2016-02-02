#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

struct Flag {
    long timestamp;
    int key;
    Flag(long t, int k) : timestamp(t), key(k) {}
};

inline bool operator<(const Flag &a, const Flag &b) {
    return a.timestamp < b.timestamp;
}

class LRUCache{
public:
    LRUCache(int capacity) :
        _seq(0), _capacity(capacity) {}

    int get(int key) {
        if (!_dict.count(key))
            return -1;
        long last = _timestamps[key];
        _set.erase(Flag(last, key));
        _set.insert(Flag(++_seq, key));
        _timestamps[key] = _seq;
        return _dict[key];
    }

    void set(int key, int value) {
        if (_dict.count(key)) {
            long last = _timestamps[key];
            _set.erase(Flag(last, key));
        }
        _set.insert(Flag(++_seq, key));
        _timestamps[key] = _seq;
        _dict[key] = value;
        if (_set.size() > _capacity) {
            auto first = _set.begin();
            int key = first->key;
            _dict.erase(key);
            _timestamps.erase(key);
            _set.erase(first);
        }
    }
private:

    int _capacity;
    long _seq;
    std::set<Flag> _set;
    unordered_map<int, int> _dict;
    unordered_map<int, long> _timestamps;
};

int main() {
    LRUCache lrc(5);
    lrc.set(1,10);
    lrc.set(2,20);
    lrc.set(3,30);
    lrc.set(4,40);
    lrc.set(5,50);
    lrc.set(6,60);
    cout << lrc.get(1) << endl;
    cout << lrc.get(2) << endl;
    cout << lrc.get(3) << endl;
    cout << lrc.get(4) << endl;
    cout << lrc.get(5) << endl;
    cout << lrc.get(6) << endl;
}
