class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        int offset = 1;

        for (int i = 1; i <= n; i ++) {
            // cout << i << endl;
            if (i == offset * 2) {
                offset = offset * 2;
                dp[i] = 1;
                continue;
            }

            dp[i] = 1 + dp[i - offset];
        }

        return dp;
    }
};

// 01  1
// 10  1
// 11  2
// 100 1
// 101 2
// 110 2
// 111 3
// 1000 1
// 10001 2