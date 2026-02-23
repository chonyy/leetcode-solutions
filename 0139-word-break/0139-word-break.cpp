class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i ++) {
            for (auto& word : dict) {
                if (word.size() > i) {
                    continue;
                }

                int len = word.size();
                string sub = s.substr(i - len, len);

                if (sub == word && dp[i - len]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

// dp[i] = possible to form words till len i
// dp[i] = dp[i - len] && len substring is in word