class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(2001, 0);
        dp[1000] = 1;

        for (int i = 0; i < n; i ++) {
            vector<int> temp(2001, 0);
            int num = nums[i];

            for (int j = -1000; j <= 1000; j ++) {
                int idx= j + 1000;

                if (dp[idx] > 0) {
                    temp[idx - num] += dp[idx];
                    temp[idx + num] += dp[idx];
                }
            }

            swap(temp, dp);
        }

        return dp[target + 1000];
    }
};

// -1000 -> 0

// 0 -> 1000

// 1000 -> 2000

// 1,1,1   target = 1


// -2 -1 0 1 2
//     1   1
// 1     2   1
//   3     3 
