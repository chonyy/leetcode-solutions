class Solution {
public:
    vector<vector<pair<int,int>>> graph;

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        graph.resize(n);

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], 0});
            graph[e[1]].push_back({e[0], 1});
        }

        int prev = visit(-1, 0);
        vector<int> res(n);
        getAns(-1, 0, prev, res);

        return res;
    }

    void getAns(int parent, int node, int rev, vector<int>& res) {
        res[node] = rev;

        for (auto& [nei, cost] : graph[node]) {
            if (nei == parent) continue;
            getAns(node, nei, rev + (cost == 1 ? -1 : 1), res);
        }
    }

    int visit(int parent, int node) {
        int reverse = 0;

        for (auto& [nei, cost] : graph[node]) {
            if (nei == parent) continue;
            reverse += cost;
            reverse += visit(node, nei);
        }

        return reverse;
    }
};