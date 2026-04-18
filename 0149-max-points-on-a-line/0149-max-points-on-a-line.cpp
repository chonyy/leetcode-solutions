class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 1;

        for (int i = 0; i < n; i ++) {
            // reset the slopeCount for each point so the y offset doesn't matter
            unordered_map<float,int> slopeCount;
            auto& p1 = points[i];

            for (int j = i + 1; j < n; j ++) {
                auto& p2 = points[j];
                float slope;
                if (p1[0] == p2[0]) {
                    slope = INT_MAX;
                }
                else {
                    slope = (float)(p1[1] - p2[1]) / (p1[0] - p2[0]);
                }

                if (slopeCount[slope] == 0) {
                    slopeCount[slope] = 1;
                }

                slopeCount[slope] ++;
                res = max(res, slopeCount[slope]);
            }
        }

        return res;
    }
};