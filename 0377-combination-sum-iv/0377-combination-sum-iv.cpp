class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
    
        for (int i = 1; i <= target; i ++) {
            for (int num : nums) {
                int need = i - num;
                if (need < 0) {
                    continue;
                }

                dp[i] += dp[need];
            }
        }

        return dp[target];
    }
};


// 0 1 2 3 4
// 1 1 2 3 4