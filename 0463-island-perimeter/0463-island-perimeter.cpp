class Solution {
public:
    vector<vector<int>> dirs = {{0,1 }, {1, 0}, {0, -1}, {-1, 0}};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == 1) {
                    for(auto& dir : dirs) {
                        int newCol = j + dir[0];
                        int newRow = i + dir[1];
                        
                        if(newCol < 0 || newCol >= cols || newRow < 0 || newRow >= rows) {
                            ans ++;
                            continue;
                        }
                        if(grid[newRow][newCol] == 0) {
                            ans ++;
                            continue;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};