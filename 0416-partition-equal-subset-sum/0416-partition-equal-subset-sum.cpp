class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2) {
            return false;
        }

        int target = sum / 2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int num : nums) { // ensure num is only use once, needs to be on outer loop
            vector<bool> temp = dp;
            for (int i = 1; i <= target; i ++) { // need to be in reverse to reuse previous round
                int need = i - num;

                if (need < 0) {
                    continue;
                }

                if (dp[need]) {
                    temp[i] = true;
                }
            }
            swap(temp, dp);
        }
       
        return dp[target];
    }
};