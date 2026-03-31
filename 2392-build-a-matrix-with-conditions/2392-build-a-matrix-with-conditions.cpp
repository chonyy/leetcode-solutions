class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // topological sort for both row conditions and col coditions
        // map dependency order to it's index
        // build matrix with index
        vector<int> rowOrders = getOrder(rowConditions, k);
        vector<int> colOrders = getOrder(colConditions, k);

        if (rowOrders.size() != k || colOrders.size() != k)
            return {};

        unordered_map<int,int> rowToIdx;
        unordered_map<int,int> colToIdx;

        for (int i = 0; i < k; i ++) {
            rowToIdx[rowOrders[i]] = i;
        }
        for (int i = 0; i < k; i ++) {
            colToIdx[colOrders[i]] = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));

        for (int i = 1; i <= k; i ++) {
            int r = rowToIdx[i];
            int c = colToIdx[i];
            res[r][c] = i;
        }

        return res;
    }

    vector<int> getOrder(vector<vector<int>>& conditions, int k) {
        unordered_map<int,int> inDegree;
        unordered_map<int, vector<int>> graph;

        for (auto& c : conditions) {
            graph[c[0]].push_back(c[1]);
            inDegree[c[1]] ++;
        }

        queue<int> q;
        for (int i = 1; i <= k; i ++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            // cout << cur << endl;
            res.push_back(cur);

            for (int nei : graph[cur]) {
                inDegree[nei] --;

                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return res;
    }
};