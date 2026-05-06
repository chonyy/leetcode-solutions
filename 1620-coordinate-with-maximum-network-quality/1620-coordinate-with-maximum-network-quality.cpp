class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> res = {0, 0};
        int curMax = 0;

        for (int i = 0; i <= 50; i ++) {
            for (int j = 0; j <= 50; j ++) {
                int cur = 0;
                for (auto& t : towers) {
                    cur += quality(i, j, t, radius);
                }

                if (cur > curMax) {
                    curMax = max(curMax, cur);
                    res[0] = i;
                    res[1] = j;
                }
            }
        }

        return res;
    }

    int quality(int r, int c, vector<int>& tower, int radius) {
        int dx = r - tower[0];
        int dy = c - tower[1];
        double dist = sqrt(dx * dx + dy * dy);

        if (dist > radius) {
            return 0;
        }

        return tower[2] / (1 + dist);
    }
};