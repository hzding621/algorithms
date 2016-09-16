#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values,
                                vector<pair<string, string>> queries) {

        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            auto& p = equations[i];
            graph[p.first][p.second] = values[i];
            graph[p.second][p.first] = 1 / values[i];
        }

        unordered_map<string, bool> visited;

        vector<double> result;
        for (auto& query: queries) {
            if (!graph.count(query.first) || !graph.count(query.second)) {
                result.push_back(-1);
            } else {
                double partial = 1, answer;
                visited.clear();
                visited[query.first] = true;
                bool found = dfs(answer, partial, graph, visited, query.first, query.second);
                if (found) {
                    result.push_back(answer);
                } else {
                    result.push_back(-1);
                }
            }

        }
        return result;
    }
private:

    bool dfs(double& answer,
             double& partial,
             unordered_map<string, unordered_map<string, double>>& graph,
             unordered_map<string, bool>& visited,
             const string& current,
             const string& target) {
        if (current == target) {
            answer = partial;
            return true;
        }
        for (auto& p: graph[current]) {
            auto& neighbor = p.first;
            double v = p.second;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                partial *= v;
                bool result = dfs(answer, partial, graph, visited, neighbor, target);
                partial /= v;
                visited[neighbor] = false;
                if (result) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {

    vector<pair<string, string>> equations = {
            {"a", "b"},
            {"b", "c"}
    };

    vector<double> values = {2.0, 3.0};
    vector<pair<string, string>> queries = {
            {"a", "c"},
            {"b", "a"},
            {"a", "e"},
            {"a", "a"},
            {"x", "x"}
    };

    Solution sol;

    auto answers = sol.calcEquation(equations, values, queries);
    for (double d: answers) {
        cout << d << endl;
    }

    return 0;
}