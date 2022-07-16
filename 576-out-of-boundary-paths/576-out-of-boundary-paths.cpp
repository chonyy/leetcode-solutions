class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N+1, 0)));
        
        for(int k = 1; k <= N; k ++) {
            for(int i = 0; i < m; i ++) {
                for(int j = 0; j < n; j ++) {
                    for(auto dir : dirs) {
                        int newRow = i + dir[0];
                        int newCol = j + dir[1];
                        if(newRow >= m || newRow < 0 || newCol >= n || newCol < 0)
                            dp[i][j][k] += 1;
                        else
                            dp[i][j][k] = (dp[i][j][k] + dp[newRow][newCol][k-1]) % mod;
                    }
                }
            }
        }
        
        return dp[i][j][N];
    }
};