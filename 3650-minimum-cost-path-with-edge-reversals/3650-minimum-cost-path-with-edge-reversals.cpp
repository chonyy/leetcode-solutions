class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> graph;

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], 2 * e[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        unordered_set<int> visited;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited.contains(node)) {
                continue;
            }
            visited.insert(node);

            if (node == n -1) {
                return cost;
            }

            for (auto [next, weight] : graph[node]) {
                pq.push({cost + weight, next});
            }
        }

        return -1;
    }
};


// <cost, node, prev, usedSwitch>