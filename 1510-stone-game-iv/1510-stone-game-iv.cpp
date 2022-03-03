class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        dp[0] = false;
        dp[1] = true;
        
        for(int i = 2; i <= n; i ++) {
            bool res = false;
            for(int j = 1; j * j <= i; j ++) {
                res |= !dp[i-j*j];                
            }
            dp[i] = res;
        }
        
        return dp[n];
    }
};

// 1: w
// 2 : l
// 3: w
// 4: w
// 5: 