class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));  // ✅ +1
        return dfs(s, 0, p, 0, dp);
    }
    
    bool dfs(string& s, int i, string& p, int j, vector<vector<int>>& dp) {
        if (j == p.size()) return i == s.size();
        if (dp[i][j] != -1) return dp[i][j];

        bool firstMatch = i < s.size() && (p[j] == '.' || s[i] == p[j]);

        bool res;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            res = dfs(s, i, p, j + 2, dp) ||              // zero times
                (firstMatch && dfs(s, i + 1, p, j, dp)); // one+ times
        } else {
            res = firstMatch && dfs(s, i + 1, p, j + 1, dp);
        }

        return dp[i][j] = res;
    }
};