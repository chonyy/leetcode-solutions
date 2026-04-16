class Solution {
public:
    int res = 0;
    int total = 0;
    int rows;
    int cols;
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startR;
        int startC;
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                }

                if (grid[i][j] == 0) {
                    total ++;
                }
            }
        }

        dfs(grid, visited, startR, startC, 0);

        return res;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int steps) {
        if (grid[r][c] == -1) {
            return;
        }

        if (grid[r][c] == 2) {
            // cout << steps << endl;
            if (steps == total + 1) {
                res ++;
            }
            return;
        }

        if (visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        // cout << r << " " << c << endl;

        for (auto& dir : dirs) {
            int newR = r + dir.first;
            int newC = c + dir.second;

            if (newR >= rows || newR < 0 || newC >= cols || newC < 0) {
                continue;
            }

            dfs(grid, visited, newR, newC, steps + 1);
        }

        visited[r][c] = false;
    }
};