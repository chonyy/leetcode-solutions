class Solution {
public:
    int minDistance(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);                    
                }
            }
        }
        
        int size = dp[n][m];
        
        return n+m-2*size;
    }
};