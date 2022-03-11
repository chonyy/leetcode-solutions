class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1, false));
        
        dp[0][0] = true;
        int i = 0;
        while(i < m) {
            if(p[i] != '*')
                break;
            dp[0][i+1] = true;
            i ++;
        }
        
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j++) {
                if(p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        
        // for(int i = 0; i <= n; i ++) {
        //     for(int j = 0; j <= m; j ++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return dp[n][m];
    }
};