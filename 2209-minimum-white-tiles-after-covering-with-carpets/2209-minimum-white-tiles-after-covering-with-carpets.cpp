class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(n+1, vector<int>(numCarpets+1));
        
        for(int i = 1; i <= n; i ++) {
            for(int j = 0; j <= numCarpets; j ++) {
                if(j == 0) {
                    dp[i][j] = (floor[i-1] == '1') + dp[i-1][j];
                    continue;
                }
                
                int noCover = (floor[i-1] == '1') + dp[i-1][j];
                int cover = dp[max(i - carpetLen, 0)][j-1];
                dp[i][j] = min(cover, noCover);
            }
        }
        
        return dp[n][numCarpets];
    }
    
};

// dp[i][j] = use j carpet to i idx => min white tiles 