class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // init
        for(int i = 0; i < n; i ++) {
            dp[i][m] = n - i;
        }

        for(int j = 0; j < m; j ++) {
            dp[n][j] = m - j;
        }

        // print(dp, n, m );


        // build dp
        for(int i = n-1; i >= 0; i --) {
            for(int j = m-1; j >= 0; j --) {
                char c1 = str1[i];
                char c2 = str2[j];

                if(c1 == c2) {
                    // cout << "same " << c1 << endl;
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    // cout << "not same" << endl;
                    dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + 1;
                }

                // cout << dp[i][j] << " ";
            }

            // cout << endl;
        }

        // for(int i = 0; i <= n; i ++) {
        //     for(int j = 0; j <= m; j ++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // build seq
        int i = 0;
        int j = 0;
        string res = "";

        while(i < n && j < m) {
            if(str1[i] == str2[j]) {
                res += str1[i];
                i ++;
                j ++;
            }
            else {
                if(dp[i+1][j] < dp[i][j+1]) {
                    res += str1[i];
                    i ++;
                }
                else {
                    res += str2[j];
                    j ++;
                }
            }
            cout << endl;
        }

        while(i < n) {
            res += str1[i];
            i ++;
        }

        while(j < m) {
            res += str2[j];
            j ++;
        }

        return res;
    }

};

//          abac
//          bac
//          ac
//          c
// cab ab b ""