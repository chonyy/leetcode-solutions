class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);

        for (int i = 2; i <= n; i ++) {
            int localMax = 0;

            for (int j = 1; j < i; j ++) {
                int diff = i - j;
                localMax = max(localMax, diff * dp[j]);
                localMax = max(localMax, diff * j);
            }

            dp[i] = localMax;
        }

        return dp[n];
    }
};