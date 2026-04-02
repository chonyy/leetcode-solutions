class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size()) {
            return false;
        }

        vector<vector<bool>> dp(m+1, vector<bool>(n+1));

        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                    continue;
                }

                int k = i + j - 1;
                bool fromS1 = i > 0 && dp[i-1][j] && s1[i-1] == s3[k];
                bool fromS2 = j > 0 && dp[i][j-1] && s2[j-1] == s3[k];
                dp[i][j] = fromS1 || fromS2;
            }
        }
        
        return dp[m][n];
    }
};


// aabcc
//   i

// dbbca
//  j

// aadbbcbcac
//    k


// bbacc
//    i

// ae
// i

// bbaeacc
//   k