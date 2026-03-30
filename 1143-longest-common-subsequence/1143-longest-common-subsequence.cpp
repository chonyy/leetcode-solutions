class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n]; // can shrink to 1d
    }
};

// dp[i][j] = longest common subsequence between text1[0:i-1] and text2[0:j-1] 

// if text1[i] == text2[j], dp[i+1][j+1] = dp[i][j]] + 1

// else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])

// abcde
// i

// ace
//  j


// ab
// ac