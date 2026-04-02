class Solution {
public:

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, 0);

        for (int i = n-1; i >= 0; i --) {
            int stone = 0;
            int res = INT_MIN;

            for (int j = 0; j < 3; j ++) {
                int pick = i + j;
                if (pick < n) {
                    stone += stoneValue[pick];
                }

                int prevWin = pick+1 >= n ? 0 : dp[pick+1];
                res = max(res, stone - prevWin);
            }

            dp[i] = res;
        }

        if (dp[0] == 0) {
            return "Tie";
        }
        else if (dp[0] > 0) {
            return "Alice";
        }

        return "Bob";
    }
};