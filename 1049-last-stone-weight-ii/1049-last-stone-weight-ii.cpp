class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;

        for (int stone : stones) {
            sum += stone;
        }

        int target = sum / 2;

        vector<bool> dp(target+1);
        dp[0] = true;

        // split stones to two groups, minimize the diff between two groups
        // unbounded knapsack to find the target
        for (int stone : stones) {
            for (int i = target; i > 0; i --) {
                int need = i - stone;
                if (need < 0) {
                    break;
                }

                if (dp[need]) {
                    dp[i] = true;
                }
            }
        }

        int closest = 0;
        for (int i = target; i >= 0; i --) {
            if (dp[i]) {
                closest = i;
                break;
            }
        }

        // res is the diff between two groups
        return (sum - closest) - closest;
    }
};

// 2,7,4,1,8,1

// 8 7 4 2 1 1 

// 1 4 2 1 1

// 2 1 1 1
// 1 1 1
