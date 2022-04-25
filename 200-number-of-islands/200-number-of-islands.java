class Solution {
    private int rows;
    private int cols;
    int[][] dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    
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
    
    public void bfs(char[][] grid, int row, int col) {
        Queue<Pair<Integer,Integer>> q = new LinkedList<>();
        q.offer(new Pair(row, col));
        
        while(q.size() > 0) {
            var cur = q.poll();
            int curRow = cur.getKey();
            int curCol = cur.getValue();
            
            for(var dir : dirs) {
                int newRow = curRow + dir[0];
                int newCol = curCol + dir[1];
                
                if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    continue;
                }
                if(grid[newRow][newCol] == '0') {
                    continue;
                }
                
                grid[newRow][newCol] = '0';
                q.offer(new Pair(newRow, newCol));
            }
        }
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