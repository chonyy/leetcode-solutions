class Solution {
public:
    long long res = 0;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> graph;
        for (auto& r : roads) {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }

        dfs(graph, 0, -1, seats);
        
        return res;
    }

    int dfs(unordered_map<int, vector<int>>& graph, int node, int parent, int seats) {
        long long people = 1;

        for (auto nei : graph[node]) {
            if (nei == parent) {
                continue;
            }
            people += dfs(graph, nei, node, seats);
        }

        // cout << "node " << node << endl;
        // cout << "people " << people << endl;
        // cout << "seats " << seats << endl;
        // cout << "res " << res << endl;
        if (node != 0) {
            res += ceil((double)people / seats);
        }

        return people;
    }
};