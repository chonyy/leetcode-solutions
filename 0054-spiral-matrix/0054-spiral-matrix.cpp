class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;

        int rowLow = 0, rowHigh = row-1, colLow = 0, colHigh = col-1;

        while(rowLow <= rowHigh && colLow <= colHigh) {
            for(int i = colLow; i <= colHigh; i ++) {
                res.push_back(matrix[rowLow][i]);
            }
            rowLow ++;
            if(rowHigh < rowLow)
                break;
            for(int i = rowLow; i <= rowHigh; i ++) {
                res.push_back(matrix[i][colHigh]);
            }
            colHigh --;
            if(colHigh < colLow)
                break;
            for(int i = colHigh; i >= colLow; i --) {
                res.push_back(matrix[rowHigh][i]);
            }
            rowHigh --;
            if(rowHigh < rowLow)
                break;
            for(int i = rowHigh; i >= rowLow; i --) {
                res.push_back(matrix[i][colLow]);
            }
            colLow ++;
            if(colHigh < colLow)
                break;
        }
        return res;
    }
};