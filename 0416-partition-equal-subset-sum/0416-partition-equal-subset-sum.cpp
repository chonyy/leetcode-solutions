class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2) {
            return false;
        }

        int target = sum / 2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= 1; i --) {
                if (num > i) {
                    continue;
                }

                int need = i - num;
                if (dp[need]) {
                    // cout << i << " using " << num << endl;
                    dp[i] = true;
                }
            }
        }

        return dp[target];
    }
};