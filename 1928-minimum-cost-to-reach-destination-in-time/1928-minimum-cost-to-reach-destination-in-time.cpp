class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        unordered_map<int, vector<pair<int,int>>> graph;
        int n = passingFees.size();

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        // minHeap {cost, time, node}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({passingFees[0], 0, 0});
        vector<int> minTime(n, INT_MAX);

        while (!pq.empty()) {
            int cost = pq.top()[0];
            int time = pq.top()[1];
            int node = pq.top()[2];
            pq.pop();

            // if n -1, return result
            // if time[node] <= time, skip
            if (node == n-1) {
                return cost;
            }

            if (minTime[node] <= time) {
                continue;
            }
            minTime[node] = time;

            // explore neighbors
            // if less then maxTime, add
            auto& neighbors = graph[node];
            for (auto nei : neighbors) {
                int fee = passingFees[nei.first];
                int travelTime = nei.second;

                int newCost = cost + fee;
                int newTime = time + travelTime;

                if (newTime > maxTime) {
                    continue;
                }

                pq.push({newCost, newTime, nei.first});
            }
        }

        return -1;
    }
};