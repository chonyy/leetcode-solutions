class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dp(n+1, INT_MAX);
        dp[k] = 0;
        
        for(int i = 0; i < n-1; i ++) {
            for(auto& edge : times) {
                int from = edge[0];
                int to = edge[1];
                int time = edge[2];
                
                if(dp[from] != INT_MAX && dp[from] + time < dp[to]) {
                    dp[to] = dp[from] + time;
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            ans = max(ans, dp[i]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};