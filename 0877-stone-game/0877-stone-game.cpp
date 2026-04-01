class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sum = 0;
        int n = piles.size();
        for (int p : piles) {
            sum += p;
        }

        vector<vector<int>> dp(n, vector<int>(n));

        int alice = getStones(piles, 0, piles.size() - 1, dp);

        return alice >= sum / 2;
    }

    int getStones(vector<int>& piles, int l, int r, vector<vector<int>>& dp) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r] != 0) {
            return dp[l][r];
        }

        int takeLeft = piles[l] + max(getStones(piles, l+1, r-1, dp), getStones(piles, l+2, r, dp));
        int takeRight = piles[r] + max(getStones(piles, l+1, r-1, dp), getStones(piles, l, r-2, dp));
        int res = max(takeLeft, takeRight);

        dp[l][r] = res;
        return res;
    }
};


// 5 10 1 5
// 5 10 1