class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n+1, 0));
        int maxLen = 1;
        int startIdx = 0;

        for (int i = n; i >= 1; i --) {
            for (int j = i; j <= n; j ++) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }

                if (s[i-1] == s[j-1] && (dp[i+1][j-1] || j - i <= 1)) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    startIdx = i -1;
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};

// dp[i][i] = 1;

// dp[i][j] = s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1]), +2


//   b a b a d
// b 1 0 3 0 0
// a.  1 0 1 0
// b.    1 0 0
// a       1 0
// d.        1


//     c b b d
//   0 0 0 0 0
// c 0
// b 0.  1 
// b 0.    1 0
// d 0       1