class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        // ✅ 2D vector instead of unordered_map
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return dfs(nums, 1, n - 2, dp);
    }

    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (l > r) return 0;

        // ✅ O(1) lookup instead of O(log n) string hash
        if (dp[l][r] != -1) return dp[l][r];

        int res = 0;
        for (int i = l; i <= r; i++) {
            int coin = nums[l-1] * nums[i] * nums[r+1];
            coin += dfs(nums, l, i-1, dp) + dfs(nums, i+1, r, dp);
            res = max(res, coin);
        }

        return dp[l][r] = res;
    }
};