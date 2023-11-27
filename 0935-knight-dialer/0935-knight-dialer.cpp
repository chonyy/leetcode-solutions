class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    int dfs(int n, int row, int col, vector<vector<vector<int>>>& mem) {
        if(row < 0 || row >= 4 || col < 0 || col >= 3)
            return 0;
        if(row == 3 && col != 1)
            return 0;
        
        if(n == 1)
            return 1;
        
        if(mem[row][col][n] != 0)
            return mem[row][col][n];
        
        int res = 0;
        for(auto& dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            
            res = res % mod + (dfs(n-1, newRow, newCol, mem) % mod);
        }
        
        return mem[row][col][n] = res;
    }
    
    int knightDialer(int n) {
        int res = 0;
        vector<vector<vector<int>>> mem = vector<vector<vector<int>>>(4, vector<vector<int>>(3, vector<int>(n+1, 0)));
        
        for(int i = 0; i < 4; i ++) {
            for(int j = 0; j < 3; j ++) {
                res += dfs(n, i, j, mem) % mod;
                res = res % mod;
            }
        }
        
        return res % mod;
    }
};