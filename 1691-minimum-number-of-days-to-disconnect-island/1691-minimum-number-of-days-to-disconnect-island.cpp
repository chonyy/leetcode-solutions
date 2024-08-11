class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows;
    int cols;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        // cout << r << " " << c << endl;
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return;
        }

        grid[r][c] = 0;

        for(auto& dir : dirs) {
            dfs(grid, r + dir[0], c + dir[1]);
        }
    }

    int numberOfIslands(vector<vector<int>>& grid) {
       vector<vector<int>> g = grid;
       int res = 0;

        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(g[i][j]) {
                    dfs(g, i, j);
                    res ++;
                }
            }
        }

        return res;
    }

    int minDays(vector<vector<int>>& grid) {
       rows = grid.size();
       cols = grid[0].size();
        // check 0 islands
        int islands = numberOfIslands(grid);
        if(islands == 0 || islands > 1)
            return 0;

        // check 1 island
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j]) {
                    grid[i][j] = 0;

                    int islands = numberOfIslands(grid);
                    if(islands == 0 || islands > 1) {
                        return 1;
                    }

                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};