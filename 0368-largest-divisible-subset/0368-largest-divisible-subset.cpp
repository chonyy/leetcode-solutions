class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);

        int globalMax = 0;
        int maxIdx = 0;

        for (int i = 1; i < n; i ++) {
            int curMax = 0;
            for (int j = i-1; j >= 0; j --) {
                if (nums[i] % nums[j] == 0) {
                    curMax = max(curMax, dp[j]);
                }
            }
            dp[i] = curMax + 1;
            if (dp[i] > globalMax) {
                globalMax = dp[i];
                maxIdx = i;
            }
        }

        vector<int> res;
        res.push_back(nums[maxIdx]);
        int targetSize = globalMax - 1;

        // go backward from maxIdx
        while (res.size() < globalMax) {
            if (res.back() % nums[maxIdx] == 0 && dp[maxIdx] == targetSize) {
                res.push_back(nums[maxIdx]);
                targetSize --;
            }
            maxIdx --;
        }

        return res;
    }

};