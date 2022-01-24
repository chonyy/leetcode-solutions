class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        
        dp[0] = 0;
        
        for(int i = 0; i <= amount; i ++) {
            for(int coin : coins) {
                int need = i - coin;
                if(need >= 0)
                    dp[i] = min(dp[i], dp[need] + 1);
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};