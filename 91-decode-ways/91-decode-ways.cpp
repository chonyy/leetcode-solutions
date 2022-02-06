class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] =  s[0] == '0' ? 0 : 1;
        
        for(int i = 2; i <= n; i ++) {
            int prevOne = stoi(s.substr(i-1, 1));
            int prevTwo = stoi(s.substr(i-2, 2));
            
            if(prevOne > 0 && prevOne <= 9) {
                dp[i] += dp[i-1];
            }
            if(prevTwo >= 10 && prevTwo <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};

// 0
    
// 226