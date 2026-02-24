class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;

        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int k = i + j - 1;
                if (i == 0) {
                    dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[k]);;
                }
                else if (j == 0) {
                    dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[k]);
                }
                else {
                    bool fromS2 = dp[i][j-1] && (s2[j-1] == s3[k]);
                    bool fromS1 = dp[i-1][j] && (s1[i-1] == s3[k]);
                    dp[i][j] = fromS2 || fromS1;
                }
            }
        }

        return dp[n][m];
    }
};

// two pointers will not work

// ab
// i

// acc
// j

// acacb
// k



//     "" a b
// ""  0  t f
// a.  t  f  
// c
// c
 

// acacb
//   k