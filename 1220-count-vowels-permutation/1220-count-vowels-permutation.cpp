class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<long long > dp(5, 1);
        
        for(int i = 1; i < n; i ++) {
            vector<long long> temp(5);
            
            temp[0] = (dp[1] + dp[2] + dp[4]) % mod;
            temp[1] = (dp[0] + dp[2]) % mod;
            temp[2] = (dp[1] + dp[3]) % mod;
            temp[3] = (dp[2]) % mod;
            temp[4] = (dp[2] + dp[3]) % mod;
            
            swap(dp, temp);
        }
        
        
        int ans = 0;
        for(int num : dp) {
            ans = (ans + num) % mod;
        }
        
        return ans;
    }
};
