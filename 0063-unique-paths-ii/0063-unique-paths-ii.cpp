class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols));
        
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        dp[0][0] = 1;
        
        for(int i = 1; i < rows; i ++) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
                continue;
            }           
            dp[i][0] = dp[i-1][0] == 0 ? 0 : 1;
        }
        
        for(int i = 1; i < cols; i ++) {
            if(obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
                continue;
            }           
            dp[0][i] = dp[0][i-1] == 0 ? 0 : 1;
        }
        
        // for(int i = 0; i < rows; i ++) {
        //     for(int j = 0; j < cols; j ++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for(int i = 1; i < rows; i ++) {
            for(int j = 1; j < cols; j ++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }            
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[rows-1][cols-1];
    }
};