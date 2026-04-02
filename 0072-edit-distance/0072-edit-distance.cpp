class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0) {
                    dp[i][j] = j;
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = i;
                    continue;
                }

                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                    dp[i][j] ++;
                }
            }
        }

        return dp[n][m];
    }
};


//     r o s
//   0 1 2 3
// h 1 1 2 3
// o 2 2 1 2
// r 3 2 2 2
// s 4 3 3 2
// e 5 4 4 3


// horse
// ros

// hors
// ros

// hor
// ro

// ho
// ro

// h
// r

