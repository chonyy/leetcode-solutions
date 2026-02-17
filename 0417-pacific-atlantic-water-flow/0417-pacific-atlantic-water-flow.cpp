class Solution {
public:
    int rows;
    int cols;
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        
        vector<vector<int>> pWater(rows, vector<int>(cols, 0));
        vector<vector<int>> aWater(rows, vector<int>(cols, 0));

        // visit pacific with dfs
        for (int i = 0; i < rows; i ++) {
            for (int j = 0;j < cols; j ++) {
                if (i == 0 || j == 0) {
                    dfs(heights, pWater, i, j);
                }
            }
        }

        // visit atlantic with dfs
        for (int i = 0; i < rows; i ++) {
            for (int j = 0;j < cols; j ++) {
                if (i == rows - 1 || j == cols - 1) {
                    dfs(heights, aWater, i, j);
                }
            }
        }

        vector<vector<int>> res;
        // check cells both visited
        for (int i = 0; i < rows; i ++) {
            for (int j = 0;j < cols; j ++) {
                if (pWater[i][j] && aWater[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int r, int c) {
        visited[r][c] = 1;
        // cout << r << " " << c << endl;

        for (auto& dir : dirs) {
            int newR = r + dir.first;
            int newC = c + dir.second;

            if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                continue;
            }

            if (visited[newR][newC]) {
                continue;
            }

            if (heights[newR][newC] < heights[r][c]) {
                continue;
            }

            dfs(heights, visited, newR, newC);
        }
    }
};