class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));

        return solve(s, 0, t, 0);
    }

    int solve(string& s, int i, string& t, int j) {
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = 0;
        if (s[i] == t[j]) {
            res += solve(s, i+1, t, j);
            res += solve(s, i+1, t, j+1);
        }
        else {
            res += solve(s, i+1, t, j);
        }
    
        dp[i][j] = res;
        return res;
    }
};