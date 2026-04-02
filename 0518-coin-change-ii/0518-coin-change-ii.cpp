class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = 1; i <= amount; i ++) {
                int need = i - coin;

                if (need < 0) {
                    continue;
                }

                dp[i] += dp[need];
            }
        }

        return dp[amount];
    }
};