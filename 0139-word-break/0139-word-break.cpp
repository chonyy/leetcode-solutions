class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; i ++) {
            for(auto& word : dict) {
                if(word.size() <= i) {
                    int start = i - word.size();
                    if(dp[start] == false) {
                        continue;
                    }
                    
                    string sub = s.substr(start, word.size());
                    if(sub == word) {
                        dp[i] = true;
                    }
                }
            }
        }
        
        return dp[n];
    }
};