class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        if (startFuel >= target) {
            return 0;
        }

        vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
        dp[0][0] = startFuel;

        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= i; j ++) {
                if (j == 0) {
                    dp[i][j] = startFuel;
                    continue;
                }

                dp[i][j] = dp[i-1][j];

                if (dp[i-1][j-1] >= stations[i-1][0]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stations[i-1][1]);
                }
            }
        }

        for (int j = 0; j <= n; j++) {
            if (dp[n][j] >= target) return j;
        }

        return -1;
    }
};

// dp[i][j] = at ith stop, max reach with j stops

// for i in n
//     for j in 1 to i
//         dp[i][j] = max(dp[i-1][j-1], dp[i][j-1] + );

// res = first j that dp[i][j] >= target

// [10,60],[20,30],[30,30],[60,40]

// dp[i][0] = starFuel

//    0  1  2  3  4
// 0 10. 0  0. 0. 0
// 1 10. 
// 2 10
// 3 10
// 4 10