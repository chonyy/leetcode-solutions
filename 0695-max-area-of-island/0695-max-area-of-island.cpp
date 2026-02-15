class Solution {
public:
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows;
    int cols;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int res = 0;

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                res  = max(res, find(grid, i, j));
            }
        }

        return res;
    }

    int find(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return 0;
        }

        if (grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        int area = 1;

        for (auto& dir : dirs) {
            int newR = r + dir.first;
            int newC = c + dir.second;

            area += find(grid, newR, newC);
        }

        return area;
    }
};