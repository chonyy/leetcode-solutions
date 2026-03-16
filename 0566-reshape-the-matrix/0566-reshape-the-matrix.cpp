class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();

        if (r * c != rows * cols) {
            return mat;
        }

        vector<vector<int>> res(r, vector<int>(c, 0));

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                int len = i * cols + j;

                int newR = len / c;
                int newC = len % c;

                // cout << newR << " " << newC << endl;

                res[newR][newC] = mat[i][j];
            }
        }

        return res;
    }
};