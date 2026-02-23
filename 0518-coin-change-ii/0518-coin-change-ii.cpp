class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount+1);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int i = 1; i <= amount; i ++) {
                if (coin > i) {
                    continue;
                }

                int need = i - coin;
                dp[i] += dp[need];
            }
        }

        return dp[amount];
    }
};