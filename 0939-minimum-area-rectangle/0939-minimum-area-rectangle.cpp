class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> seen;

        for (auto& p : points) {
            seen[p[0]].insert(p[1]);
        }

        int n = points.size();
        int res = INT_MAX;

        for (int i = 0; i < n; i ++) {
            for (int j = i +1; j < n; j ++) {
                auto& p1 = points[i];
                auto& p2 = points[j];

                int x1 = p1[0];
                int x2 = p2[0];
                int y1 = p1[1];
                int y2 = p2[1];

                if (x1 == x2 || y1 == y2) {
                    continue;
                }

                // 3,1   4,3
                // 3,4.  4,1
                if (seen[x1].contains(y2) && seen[x2].contains(y1)) {
                    res = min(res, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

// 1: 1, 3
// 3, 1, 3
// 2, 2

// 1: 1, 3
// 3: 1, 3
// 4: 1, 3