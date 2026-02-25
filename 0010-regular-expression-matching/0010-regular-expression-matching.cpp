class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));  // ✅ +1
        return dfs(s, 0, p, 0, dp);
    }

    bool dfs(string& s, int i, string& p, int j, vector<vector<int>>& dp) {
        // Pattern exhausted
        if (j == p.size()) {
            return i == s.size();
        }

        // String exhausted - check if remaining pattern can match empty
        if (i == s.size()) {
            while (j < p.size()) {
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    j += 2;
                } else {
                    return false;
                }
            }
            return true;
        }

        // Check memo
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool res;

        // ✅ Check for x* pattern (must be first!)
        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool firstMatch = (p[j] == s[i] || p[j] == '.');
            res = dfs(s, i, p, j + 2, dp) ||                    // Use x* zero times
                  (firstMatch && dfs(s, i + 1, p, j, dp));      // Use x* one+ times
        }
        // ✅ else if - No *, must match current character
        else if (p[j] == '.' || s[i] == p[j]) {
            res = dfs(s, i + 1, p, j + 1, dp);
        }
        // ✅ else - No match
        else {
            res = false;
        }

        dp[i][j] = res;
        return res;
    }
};