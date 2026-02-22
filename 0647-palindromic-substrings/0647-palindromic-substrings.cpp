class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;

        vector<vector<bool>> dp(n , vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i --) {
            for (int j = i; j < n; j ++) {
                if (i == j) {
                    dp[i][j] = true;
                    res ++;
                    continue;
                }

                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                    res ++;
                    dp[i][j] = true;
                }
            }
        }

        return res;
    }
};