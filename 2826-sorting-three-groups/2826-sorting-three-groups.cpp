class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> dp(4, 0);
        int n = nums.size();

        for (int num : nums) {
            if (num == 1) {
                dp[num] = dp[num] + 1;
            }

            if (num == 2) {
                dp[num] = max(dp[num], dp[num-1]) + 1;
            }

            if (num == 3) {
                dp[num] = max({dp[num], dp[num-1], dp[num-2]}) + 1;
            }
        }

        return n - max({dp[1], dp[2], dp[3]});
    }
};