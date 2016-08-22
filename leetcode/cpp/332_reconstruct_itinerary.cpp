#include <iostream>
#include <functional>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> graph;
        int ticketsLeft = tickets.size();
        for (auto& p: tickets) {
            graph[p.first][p.second]++;
        }
        vector<string> output;
        string s = "JFK";
        dfs(s, output, ticketsLeft, graph);
        return output;
    }
private:
    bool dfs(const string& s, vector<string>& output, int ticketsLeft, 
             unordered_map<string, map<string, int>>& graph) {
        output.push_back(s);
        for (auto& entry: graph[s]) {
            string destination = entry.first;
            if (graph[s][destination]) {

                graph[s][destination]--;
                ticketsLeft--;
                if (dfs(destination, output, ticketsLeft, graph)) {
                    return true;
                }
                graph[s][destination]++;
                ticketsLeft++;
            }
        }

        if (ticketsLeft == 0) {
            return true;
        }
        output.pop_back();
        return false;
    }
};

int main() {

    vector<pair<string, string>> tickets = {
        make_pair("JFK","ANU"),
        make_pair("JFK","TIA"),
        make_pair("EZE","AXA"),
        make_pair("TIA","ANU"),
        make_pair("TIA","ANU"),
        make_pair("TIA","JFK"),
        make_pair("ANU","EZE"),
        make_pair("ANU","JFK"),
        make_pair("AXA","TIA"),
        make_pair("ANU","TIA"),
    };

    Solution sol;
    auto vs = sol.findItinerary(tickets);
    for (auto& s: vs) {
        cout << s << endl;
    }

    return 0;
}

