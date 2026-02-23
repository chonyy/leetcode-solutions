class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (dp[j] == false) {
                    continue;
                }

                int len = i - j;
                string sub = s.substr(j, len);
                if (dict.contains(sub)) {
                    // cout << sub << endl;
                    // cout << i << endl;
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