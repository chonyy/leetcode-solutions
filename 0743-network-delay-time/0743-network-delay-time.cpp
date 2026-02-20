class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> nodeTime(n+1, INT_MAX);
        nodeTime[k] = 0;

        for (int i = 0; i < n; i ++) {
            vector<int> temp = nodeTime;
            for (auto& t : times) {
                int cur = t[0];
                int next = t[1];
                int cost = t[2];
                
                if (nodeTime[cur] == INT_MAX) {
                    continue;
                }

                if (nodeTime[cur] + cost < temp[next]) {
                    // cout << next << " " << nodeTime[cur] + cost << endl;
                    temp[next] = nodeTime[cur] + cost;
                }
            }

            swap(temp, nodeTime);
        }

        int res = 0;
        for (int i = 1; i <= n; i ++) {
            if (i == k) {
                continue;
            }
            res = max(res, nodeTime[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};