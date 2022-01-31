class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int num : nums) {
            sum += num;
        }
        int target = sum / 2;
        if(sum % 2)
            return false;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        dp[0][0] = true;
        
        for(int i = 1; i <= n; i ++) {
            int num = nums[i-1];
            for(int j = 1; j <= target; j ++) {
                int need = j - num;
                dp[i][j] = dp[i-1][j];
                if(need >= 0) {
                    dp[i][j] = dp[i][j] | dp[i-1][need];
                }
            }
        }
        
        return dp[n][target];
    }
};