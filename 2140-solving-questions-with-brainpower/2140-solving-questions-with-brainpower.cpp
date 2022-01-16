class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        
        for(int i = n-1; i >= 0; i --) {
            long long solve = questions[i][0];
            long long reach = questions[i][1] + 1;
            if(i + reach < n) {
                solve += dp[i+reach];
            }
            long long skip = i < n-1 ? dp[i+1] : 0;
            dp[i] = max(solve, skip);
        }
        
        return dp[0];
    }
};