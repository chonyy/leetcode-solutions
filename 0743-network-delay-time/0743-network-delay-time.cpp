class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;

        for (auto& t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<bool> inQueue(n+1, false);
        vector<int> dist(n+1, INT_MAX);

        queue<int> q;
        q.push({k});
        dist[k] = 0;
        inQueue[k] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            inQueue[cur] = false;

            for (auto& nei : graph[cur]) {
                int next = nei.first;
                int time = nei.second;

                if (dist[next] <= dist[cur] + time) {
                    continue;
                }
                dist[next] = dist[cur] + time;

                if (inQueue[next]) {
                    continue;
                }

                inQueue[next] = true;
                q.push(next);
            }
        }

        int res = 0;

        for (int i = 1; i <= n; i ++) {
            res = max(res, dist[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};