class Solution {
    private int rows;
    private int cols;
    
    public void dfs(char[][] grid, int row, int col) {
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
    
    public int numIslands(char[][] grid) {
        rows = grid.length;
        cols = grid[0].length;
        int count = 0;
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0;j < cols; j ++) {
                if(grid[i][j] == '1') {
                    count ++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
}