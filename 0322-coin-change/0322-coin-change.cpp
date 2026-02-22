class Solution {
public:
    // dp[i] = min coins to reach amount i
    // dp[i] = for all coins, take min dp[i-coin] + 1
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i ++) {
            for (int coin : coins) {
                int need = i - coin;

                if (need >= 0 && dp[need] != INT_MAX) {
                    dp[i] = min(dp[i], dp[need] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};