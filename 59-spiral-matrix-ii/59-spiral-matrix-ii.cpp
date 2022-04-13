class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        
        int rowStart = 0;
        int rowEnd = n - 1;
        int colStart = 0;
        int colEnd = n - 1;
        int num = 1;
        
        while(rowStart <= rowEnd && colStart <= colEnd) {
            for(int i = colStart; i <= colEnd; i ++) {
                res[rowStart][i] = num ++;
            }
            rowStart ++;
            
            for(int i = rowStart; i <= rowEnd;i ++) {
                res[i][colEnd] = num ++;
            }
            colEnd --;
            
            for(int i = colEnd; i >= colStart; i --) {
                if(rowStart <= rowEnd)
                    res[rowEnd][i] = num ++;
            }
            rowEnd --;
            
            for(int i = rowEnd; i >= rowStart; i --) {
                if(colStart <= colEnd)
                    res[i][colStart] = num ++;
            }
            colStart ++;
        }
        
        return res;
    }
};