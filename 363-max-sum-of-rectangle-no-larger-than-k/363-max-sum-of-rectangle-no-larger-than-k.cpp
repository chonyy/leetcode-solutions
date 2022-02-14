class Solution {
public:
    int getMax(vector<int>& arr, int k) {
        set<int> seen;
        seen.insert(0);
        int curSum = 0;
        int ans = INT_MIN;
        
        for(int num : arr) {
            // cout << num << " ";
            curSum += num;
            auto it = seen.lower_bound(curSum - k);
            if(it != seen.end()) {
                ans = max(ans, curSum - *it);
            }
            seen.insert(curSum);
        }
        // cout << endl;
        
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = INT_MIN;
        
        for(int l = 0; l < cols; l ++) {
            vector<int> arr(rows, 0);
            for(int r = l; r < cols; r ++) {
                for(int i = 0; i < rows; i ++) {
                    arr[i] += matrix[i][r];
                }
                
                // get max sum
                int maxx = getMax(arr, k);
                ans = max(ans, maxx);
            }
        }
        
        return ans == INT_MIN ? -1 : ans;
    }
};

// [5,-4,-3,4],
// [-3,-4,4,5],
// [5,1,5,-4]
