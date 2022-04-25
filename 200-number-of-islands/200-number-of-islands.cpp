class Solution {
public:
    int rows;
    int cols;
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count ++;
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if(row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }
        if(grid[row][col] == '0') {
            return;
        }
        
        grid[row][col] = '0';
        
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
    }
};