class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        bool goingUp = true;
        vector<int> res;

        int i = 0;
        int j = 0;

        while (res.size() < rows * cols) {
            // going up, row-1, col+1
            if (goingUp) {
                while (i >= 0 && j < cols) {
                    res.push_back(mat[i][j]);
                    i -= 1;
                    j += 1;
                }

                if (j == cols) {
                    i += 2;
                    j -= 1;
                }
                else {
                    i += 1;
                }
            }
            // going down, row+1, col-1
            else {
                while (j >= 0 && i < rows) {
                    res.push_back(mat[i][j]);
                    i += 1;
                    j -= 1;
                }

                if (i == rows) {
                    i -= 1;
                    j += 2;
                }
                else {
                    j += 1;
                }
            }

            goingUp = !goingUp;
        }

        return res;
    }
};