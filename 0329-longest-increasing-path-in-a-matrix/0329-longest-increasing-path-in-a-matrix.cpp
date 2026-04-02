class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> longest;
    int rows;
    int cols;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        longest = vector<vector<int>>(rows, vector<int>(cols, -1));

        int res = 0;

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                res = max(res, getPath(matrix, i, j));
            }
        }

        return res;
    }

    int getPath(vector<vector<int>>& matrix, int r, int c) {
        if (longest[r][c] != -1) {
            return longest[r][c];
        }

        int res = 0;

        for (auto& dir : dirs) {
            int newR = r + dir.first;
            int newC = c + dir.second;

            if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                continue;
            }

            if (matrix[newR][newC] <= matrix[r][c]) {
                continue;
            }

            res = max(res, getPath(matrix, newR, newC));
        }

        return longest[r][c] = res + 1;
    }
};