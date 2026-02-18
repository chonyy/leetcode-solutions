class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        
        for (auto& t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        unordered_set<int> visited;

        while (!pq.empty()) {
            int curTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Check visited, can't be shorter after this
            if (visited.contains(node)) {
                continue;
            }
            visited.insert(node);

            // Return immediately after all nodes visited
            if (visited.size() == n) {
                return curTime;
            }

            auto& neighbors = graph[node];
            for (auto& nei : neighbors) {
                int time = nei.second;
                int dest = nei.first;

                pq.push({curTime+time, dest});
            }
        }

        return -1;
    }
};