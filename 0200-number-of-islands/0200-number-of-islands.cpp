class Solution {
public:
    int rows;
    int cols;
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        rows = grid.size();
        cols = grid[0].size();

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                res += findIslands(grid, i, j);
            }
        }

        return res;
    }

    bool findIslands(vector<vector<char>>& grid, int r, int c) {
        // terminal condition
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }

        if (grid[r][c] == '0') {
            return false;
        }

        grid[r][c] = '0';

        for (auto& dir : dirs) {
            int newR = r + dir.first;
            int newC = c + dir.second;

            findIslands(grid, newR, newC);
        }

        return true;
    }
};