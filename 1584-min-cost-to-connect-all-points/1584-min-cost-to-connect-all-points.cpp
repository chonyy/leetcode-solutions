class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int nodes = 1;
        int cur = 0;
        int res = 0;

        unordered_set<int> visited;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (nodes < n) {
            // cout << cur << endl;
            // add to visited
            visited.insert(cur);

            // loop through all nodes
            // skip cur
            // skip visited
            // track minDist and nextNode
            int curMin = INT_MAX;
            int next = -1;
            for (int i = 0; i < n; i ++) {
                if (visited.contains(i)) {
                    continue;
                }

                int cost = abs(points[cur][0] - points[i][0]) + abs(points[cur][1] - points[i][1]);
                dist[i] = min(dist[i], cost);

                if (dist[i] < curMin) {
                    curMin = dist[i];
                    next = i;
                }
            }

            // after loop
            // res += minDist
            // cur = nextNode
            res += curMin;
            cur = next;
            nodes ++;
        }

        return res;
    }
};