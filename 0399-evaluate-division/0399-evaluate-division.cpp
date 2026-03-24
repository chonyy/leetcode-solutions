class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> graph;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        buildGraph(equations, values);


        vector<double> res;
        for (auto& q : queries) {
            res.push_back(find(graph, q[0], q[1]));
        }

        return res;
    }

    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        int n = equations.size();

        for (int i = 0; i < n; i ++) {
            auto& e = equations[i];
            double val = values[i];
            graph[e[0]].push_back({e[1], val});
            graph[e[1]].push_back({e[0], 1 / val});
        }
    }

    double find(unordered_map<string, vector<pair<string,double>>> graph, string& src, string& dest) {
        if (src == dest) {
            return graph.contains(src) ? 1.0 : -1.0;
        }

        unordered_set<string> visited;
        queue<pair<string,double>> q;

        q.push({src, 1.0});
        
        while(!q.empty()) {
            string curNode = q.front().first;
            double curValue = q.front().second;
            q.pop();

            visited.insert(curNode);

            auto& neighbors = graph[curNode];
            for(pair<string, double> nei : neighbors) {
                string& node = nei.first;
                double value = nei.second;

                if (visited.contains(node)) {
                    continue;
                }

                if (node == dest) {
                    return value * curValue; 
                }

                q.push({node, value * curValue});
            }
        }

        return -1.0;
    } 
};