class Solution {
public:
    unordered_map<int,int> dp;
    string stoneGameIII(vector<int>& stoneValue) {
        int aliceWin = solve(stoneValue, 0);

        if (aliceWin == 0) {
            return "Tie";
        }
        else if (aliceWin > 0) {
            return "Alice";
        }

        return "Bob";
    }

    int solve(vector<int>& stoneValues, int idx) {
        if (idx == stoneValues.size()) {
            return 0;
        }

        if (dp.contains(idx)) {
            return dp[idx];
        }

        // loop until 3, pick maximum
        int res = INT_MIN;
        int stones = 0;
        for (int i = 0; i < 3; i ++) {
            int pick = idx + i;
            if (pick >= stoneValues.size()) {
                break;
            }

            stones += stoneValues[pick];
            res = max(res, stones - solve(stoneValues, pick + 1));
        }

        dp[idx] = res;
        return res;
    }
};