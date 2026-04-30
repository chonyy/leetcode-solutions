class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        // calculate zeros from left, store rowZeros
        int n = grid.size();
        vector<int> rowZeros(n);
        for (int i = 0; i < n; i ++) {
            int zeros = 0;
            for (int j = n-1; j >= 0; j --) {
                if (grid[i][j] != 0) {
                    break;
                }
                zeros ++;
            }
            rowZeros[i] = zeros;
        }

        int res = 0;
        for (int i = 0; i < n; i ++) {
            // find closest satisfy
            int need = n - 1 - i;
            int j = i;
            while (j < n && rowZeros[j] < need) {
                j ++;
            }
            if (j == n) {
                return -1;
            }

            // bubble up
            while (j > i) {
                swap(rowZeros[j], rowZeros[j-1]);
                res ++;
                j --;
            }
        }

        return res;
    }
};

// 1 0 0 
// 1 1 0
// 1 0 0