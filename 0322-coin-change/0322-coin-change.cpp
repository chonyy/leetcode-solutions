class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinMin(amount+1, INT_MAX);
        coinMin[0] = 0;

        for (int i = 1; i <= amount; i ++) {
            for (int coin : coins) {
                int remain = i - coin;

                if (remain < 0 || coinMin[remain] == INT_MAX) {
                    continue;
                }

                coinMin[i] = min(coinMin[i], coinMin[remain] + 1);
            }
        }

        return coinMin[amount] == INT_MAX ? -1 : coinMin[amount];
    }
};