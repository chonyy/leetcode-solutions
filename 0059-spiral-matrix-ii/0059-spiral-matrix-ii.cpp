class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = n -1;

        int cur = 1;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; i ++) {
                res[rowStart][i] = cur;
                cur ++;
            }
            rowStart ++;

            for (int i = rowStart; i <= rowEnd; i ++) {
                res[i][colEnd] = cur;
                cur ++;
            }
            colEnd --;

            for (int i = colEnd; i >= colStart; i --) {
                res[rowEnd][i] = cur;
                cur ++;
            }
            rowEnd --;

            for (int i = rowEnd; i >= rowStart; i --) {
                res[i][colStart] = cur;
                cur ++;
            }
            colStart ++;
        }

        return res;
    }
};