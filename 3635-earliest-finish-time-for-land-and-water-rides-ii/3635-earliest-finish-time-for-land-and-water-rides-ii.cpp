class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int earliestLand = INT_MAX;
        int earliestWater = INT_MAX;

        int n = landStartTime.size();
        for (int i = 0; i < n; i ++) {
            earliestLand = min(earliestLand, landStartTime[i] + landDuration[i]);
        }

        int m = waterStartTime.size();
        for (int j = 0; j < m; j ++) {
            earliestWater = min(earliestWater, waterStartTime[j] + waterDuration[j]);
        }

        int landFirst = INT_MAX;
        int waterFirst = INT_MAX;

        for (int j = 0; j < m; j ++) {
            int waterStart = max(earliestLand, waterStartTime[j]);
            landFirst = min(landFirst, waterStart + waterDuration[j]);
        }

        for (int i = 0; i < n; i ++) {
            int landStart = max(earliestWater, landStartTime[i]);
            waterFirst = min(waterFirst, landStart + landDuration[i]);
        }

        return min(waterFirst, landFirst);
    }
};