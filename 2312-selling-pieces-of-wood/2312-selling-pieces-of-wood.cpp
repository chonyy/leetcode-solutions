class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        // Price lookup: priceMap[h][w] = price
        vector<vector<int>> priceMap(m + 1, vector<int>(n + 1, 0));
        for (auto& p : prices) {
            priceMap[p[0]][p[1]] = p[2];
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for (int h = 1; h <= m; h++) {
            for (int w = 1; w <= n; w++) {
                // Option 1: sell as-is (if price exists)
                dp[h][w] = priceMap[h][w];

                // Option 2: horizontal cut at row i
                for (int i = 1; i < h; i++) {
                    dp[h][w] = max(dp[h][w], dp[i][w] + dp[h - i][w]);
                }

                // Option 3: vertical cut at column j
                for (int j = 1; j < w; j++) {
                    dp[h][w] = max(dp[h][w], dp[h][j] + dp[h][w - j]);
                }
            }
        }

        return dp[m][n];
    }
};