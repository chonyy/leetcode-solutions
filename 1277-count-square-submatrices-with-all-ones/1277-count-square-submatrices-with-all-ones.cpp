class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> cache(rows, vector<int>(cols, 0));
        int res = 0;

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (i == 0 || j == 0) {
                    cache[i][j] = matrix[i][j];
                    res += cache[i][j];
                    continue;
                }

                if (matrix[i][j] == 0) {
                    cache[i][j] = 0;
                }
                else {
                    int neighborMin = min(cache[i-1][j-1], cache[i-1][j]);
                    neighborMin = min(neighborMin, cache[i][j-1]);
                    cache[i][j] = neighborMin + 1;
                    res += cache[i][j];
                }
            }
        }

        return res;
    }
};


// [0,1,1,1],
// [1,1,1,1],
// [0,1,1,1]


// [0,1,1,1],
// [1,1,2,2],
// [0,1,2,3]

// res = 9