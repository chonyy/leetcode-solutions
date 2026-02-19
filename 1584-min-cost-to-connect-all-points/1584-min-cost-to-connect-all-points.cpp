class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_set<int> visited;
        unordered_map<int, vector<pair<int,int>>> graph; // pointIdx => {dist, pointIdx}

        int n = points.size();

        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                auto& p1 = points[i];
                auto& p2 = points[j];

                int dist = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                // cout << dist << endl;
                graph[i].push_back({dist, j});
                graph[j].push_back({dist, i});
            }
        }

        int curCost = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});

        while (visited.size() != n) {
            int point = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            // cout << "point " << point << " cost " << cost << endl;

            if (visited.contains(point)) {
                continue;
            }

            // add cost
            curCost += cost;
            visited.insert(point);

            // traverse neighbors
            // skip visited
            vector<pair<int,int>> neighbors = graph[point];
            // cout << neighbors.size() << endl;

            for (auto& nei : neighbors) {
                if (visited.contains(nei.second)) {
                    continue;
                }

                pq.push(nei);
            }
        }

        return curCost;
    }
};