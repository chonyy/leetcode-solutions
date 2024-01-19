class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int res = INT_MAX;
        
        for(int i = 1; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                int lefCol = max(0, j-1);
                int righCol = min(cols-1, j+1);
                matrix[i][j] = min(min(matrix[i-1][lefCol], matrix[i-1][j]), matrix[i-1][righCol]) + matrix[i][j];
            }
        }
        
        for(int j = 0; j < cols; j ++) {
            res = min(res, matrix[rows-1][j]);
        }
        
        return res;
    }
};