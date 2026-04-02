class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                if (i == 0) {
                    grid[i][j] += grid[i][j-1];
                    continue;
                }

                if (j == 0) {
                    grid[i][j] += grid[i-1][j];
                    continue;
                }

                int theMin = min(grid[i-1][j], grid[i][j-1]);
                grid[i][j] += theMin;
            }
        }
        
        return grid[rows-1][cols-1];
    }
};