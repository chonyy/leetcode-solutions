class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; i ++) {
            for(int j = i-1; j >= 0; j --) {
                if(dp[j] == true) {
                    int len = i - j;
                    string sub = s.substr(j, len);
                    
                    if(dict.find(sub) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};