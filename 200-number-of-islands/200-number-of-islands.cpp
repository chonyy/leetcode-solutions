class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0},{0,-1}};
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
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
    
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = '0';
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                for(auto& dir : dirs) {
                    int newRow = cur.first + dir[0];
                    int newCol = cur.second + dir[1];
                    
                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                        continue;
                    }
                    
                    if(grid[newRow][newCol] == '0') {
                        continue;
                    }
                    
                    grid[newRow][newCol] = '0';
                    q.push({newRow, newCol});
                }
            }
        }
    }
};