class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = 1000;
        int total = 2 * offset + 1;
        vector<vector<int>> dp(n+1, vector<int>(total));
        dp[0][0 + offset] = 1;
        
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            for(int j = -1000; j <= 1000; j ++) {
                int index = j + offset;
                if(dp[i][index] > 0) {
                    if(index + num < total) {
                        dp[i+1][index+num] += dp[i][index];
                        // cout << i + 1 << " " << index+num << endl;
                        // cout << "add " << dp[i][index] << endl;
                    }
                    if(index - num >= 0) {
                        dp[i+1][index-num] += dp[i][index];
                    }
                }
            }
        }
        
        return dp[n][target + offset];
    }
};