class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // augment restriction
        // sort by id
        // update restriction based on left
        // update restriction based on right
        // loop and find max(mid, left, right);

        restrictions.push_back({1, 0});
        restrictions.push_back({n, n -1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();
        for (int i = 1; i < m ; i ++) {
            int dist = restrictions[i][0] - restrictions[i-1][0];
            int maxH = restrictions[i-1][1] + dist;
            restrictions[i][1] = min(restrictions[i][1] , maxH);
        }

        for (int i = m - 2; i >= 0 ; i --) {
            int dist = restrictions[i+1][0] - restrictions[i][0];
            int maxH = restrictions[i+1][1] + dist;
            restrictions[i][1] = min(restrictions[i][1] , maxH);
        }

        int res = 0;
        for (int i = 1; i < m; i ++) {
            int id1 = restrictions[i-1][0];
            int h1 = restrictions[i-1][1];
            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];
            int d = id2 - id1;

            int peak = (h2 + h1 + d) / 2;
            res = max(res, peak);
        }

        return res;
    }
};

// h1 + x = h2 + (d - x)
// 2x = h2 - h1 + d
// x = (h2 - h1 + d) / 2

// P = h1 + x
// p = (2h1 + h2 - h1 + d) / 2
// p = (h2 + h1 + d) / 2