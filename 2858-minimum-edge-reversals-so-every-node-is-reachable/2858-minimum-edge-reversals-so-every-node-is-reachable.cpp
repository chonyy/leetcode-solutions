class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> graph;

        for (auto& e : edges) {
            graph[e[0]][e[1]] = 0; // zero cost for normal edge
            graph[e[1]][e[0]] = 1;
        }

        int prev = visit(-1, 0, graph);
        vector<int> res(n);
        
        getAns(-1, 0, prev, graph, res);

        return res;
    }

    void getAns(int parent, int node, int rev, unordered_map<int, unordered_map<int, int>>& graph, vector<int>& res) {
        res[node] = rev;

        for (auto nei : graph[node]) {
            if (nei.first == parent) {
                continue;
            }

            // 1: hast cost, no edge, -1 to ans
            // 0: no cost, is edge, +1 to ans
            int newRev = rev + (nei.second == 1 ? -1 : 1);
            getAns(node, nei.first, newRev, graph, res);
        }
    }

    int visit(int parent, int node, unordered_map<int, unordered_map<int, int>>& graph) {
        int reverse = 0;

        auto& neighbors = graph[node];
        for (auto nei : neighbors) {
            if (nei.first == parent) {
                continue;
            }

            reverse += nei.second;
            reverse += visit(node, nei.first, graph);
        }

        return reverse;
    }
};