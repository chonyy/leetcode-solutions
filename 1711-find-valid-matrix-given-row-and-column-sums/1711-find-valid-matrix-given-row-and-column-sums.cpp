class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> res(rows, vector<int>(cols));
        
        for(int i = 0; i < rows; i ++) {
            res[i][0] = rowSum[i];
        }

        for(int j = 0; j < cols-1; j ++) {
            long long curSum = 0;
            for(int i = 0; i < rows; i ++) {
                curSum += res[i][j];
            }

            long long diff = curSum - colSum[j];

            int r = 0;
            while(diff) {
                if(res[r][j] <= diff) {
                    res[r][j+1] = res[r][j];
                    diff -= res[r][j];
                    res[r][j] = 0;
                }
                else {
                    res[r][j+1] += diff;
                    res[r][j] -= diff;
                    diff = 0;
                }

                r ++;
            }
        }

        return res;
    }
};

// 0 3
// 7 1