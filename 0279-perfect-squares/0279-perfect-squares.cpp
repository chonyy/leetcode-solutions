class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        
        for(int i = 1; i <= n; i ++) {
            int localMin = INT_MAX;
            for(int j = 1; j * j <= i; j ++) {
                int cal = i - j * j;
                localMin = min(localMin, dp[cal] + 1);
            }
            dp[i] = localMin;
        }
        
        return dp[n];
    }
};