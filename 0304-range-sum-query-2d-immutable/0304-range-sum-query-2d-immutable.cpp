class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefix = vector<vector<int>>(rows + 1, vector<int>(cols+1, 0));

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                // cout << i << " " << j << endl;
                prefix[i+1][j+1] = prefix[i][j+1] + prefix[i+1][j] - prefix[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // cout << row1 << " " << col1 << " " << row2 << " " << col2 << endl;
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */


// 3 0 1
// 5 6 3
// 1 2 0

// 3 3  4
// 8 14 18
// 9 17 21

// 0 0 0 0
// 0 3 3  4
// 0 8 14 18
// 0 9 17 21

// 21 - 4 - 9 + 3 = 11