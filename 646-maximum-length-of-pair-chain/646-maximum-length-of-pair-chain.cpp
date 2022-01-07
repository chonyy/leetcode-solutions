class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < i; j ++) {
                if(pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n-1];
    }
};

// [1, 2] [2, 3] [3, 4] [3, 6]