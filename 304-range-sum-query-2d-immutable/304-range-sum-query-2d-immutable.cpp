class NumMatrix {
public:
    vector<vector<int>> sum;
    int rows;
    int cols;
    
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        
        sum = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        
        for(int i = 1; i <= rows; i ++) {
            for(int j = 1; j <= cols; j ++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2 ++; col2 ++;
        
        return sum[row2][col2] - sum[row2][col1] - sum[row1][col2] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */