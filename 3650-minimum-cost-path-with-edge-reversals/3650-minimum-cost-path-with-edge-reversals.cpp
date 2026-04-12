class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], 2 * e[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        vector<bool> visited(n, false);

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;

            if (node == n - 1) return cost;

            for (auto [next, weight] : graph[node]) {
                if (!visited[next]) {
                    pq.push({cost + weight, next});
                }
            }
        }

        return -1;
    }
};