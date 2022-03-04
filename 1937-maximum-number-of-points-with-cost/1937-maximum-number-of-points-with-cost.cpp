class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        
        vector<long long> dp(cols, 0);
        
        for(int i = 0; i < cols; i ++) {
            dp[i] = points[0][i];
        }
        
        for(int i = 1; i < rows; i ++) {
            vector<long long> temp(cols), left(cols), right(cols);
            left[0] = dp[0];
            right[cols-1] = dp[cols-1];
            
            // get left
            for(int j = 1; j < cols; j ++) {
                left[j] = max(left[j-1] - 1, dp[j]);
            }
            
            // get right
            for(int j = cols-2; j >= 0; j --) {
                right[j] = max(right[j+1] - 1, dp[j]);
            }
            
            // get temp
            for(int j = 0; j < cols; j ++) {
                temp[j] = max(left[j], right[j]) + points[i][j];
            }
            
            swap(temp, dp);
        }
        
        long long ans = 0;
        
        for(int i = 0; i < cols; i ++) {
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

// 1 2 3

// 1 2 3     1 2 3   

// 2 7 4
    
// 2 7 6.  6 7 4

// 9 8 7