class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        int n = values.size();

        for (int i = 0; i < n; i ++) {
            auto& e = equations[i];
            double val = values[i];
            graph[e[0]][e[1]] = val;
            graph[e[1]][e[0]] = 1 / val;
        }

        for (auto& e1 : graph) {
            string k = e1.first;
            for (auto& e2 : graph) {
                string i = e2.first;
                for (auto& e3 : graph) {
                    string j = e3.first;
                    // set i => j, if i => k and k => j is set
                    if (graph[i].contains(k) && graph[k].contains(j)) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        vector<double> res;

        for (auto& q : queries) {
            if (!graph.contains(q[0]) || !graph.contains(q[1])) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(graph[q[0]][q[1]] == 0 ? -1.0 : graph[q[0]][q[1]]);
        }

        return res;
    }
};