class Solution {
public:
    int rows;
    int cols;
    void paint(vector<vector<int>>& grid, int row, int col, int color, unordered_map<int,int>& colorArea) {
        if(row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }
        if(grid[row][col] != 1) {
            return;
        }
        
        // paint it, increse colorArea
        grid[row][col] = color;
        colorArea[color] ++;
        // dfs
        paint(grid, row+1, col, color, colorArea);
        paint(grid, row-1, col, color, colorArea);
        paint(grid, row, col+1, color, colorArea);
        paint(grid, row, col-1, color, colorArea);
    }
    
    vector<vector<int>> dirs = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    
    unordered_set<int> getColors(vector<vector<int>>& grid, int row, int col) {
        unordered_set<int> uniqueColors;        
        
        for(auto& dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                continue;
            }
            uniqueColors.insert(grid[newRow][newCol]);
        }
        
        return uniqueColors;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int color = 2;
        unordered_map<int, int> colorArea;
        int ans = 0;
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == 1) {
                    paint(grid, i, j, color, colorArea);
                    color ++;
                }
            }
        }
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == 0) {
                    int candidate = 1;
                    auto colorSet = getColors(grid, i, j);
                    for(auto color: colorSet) {
                        candidate += colorArea[color];
                    }
                    ans = max(ans, candidate);    
                }
            }
        }
        
        return ans == 0 ? rows * cols : ans;
    }
};