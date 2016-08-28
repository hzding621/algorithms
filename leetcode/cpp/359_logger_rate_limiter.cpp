#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        clean(timestamp);
        if (!_lastPrintedTime.count(message)) {
            _lastPrintedTime[message] = timestamp;
            _q.push(make_pair(message, timestamp));
            return true;
        } else {
            return false;
        }
    }

private:

    queue<pair<string,int>> _q;
    unordered_map<string, int> _lastPrintedTime;

    void clean(int timestamp) {
        while (!_q.empty() && _q.front().second <= timestamp - 10) {
            _lastPrintedTime.erase(_q.front().first);
            _q.pop();
        }
    }
};

int main() {

    Logger logger;
    cout << boolalpha;
    cout << logger.shouldPrintMessage(1, "foo") << endl;
    // cout << logger.shouldPrintMessage(2,"bar") << endl;
    // cout << logger.shouldPrintMessage(3,"foo") << endl;
    // cout << logger.shouldPrintMessage(8,"bar") << endl;
    cout << logger.shouldPrintMessage(2,"foo") << endl;
    cout << logger.shouldPrintMessage(11,"foo") << endl;


    return 0;
}