class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= target; i ++) {
            for(int num : nums) {
                int need = i - num;
                if(need >= 0) {
                    dp[i] += dp[need];
                }
            }
        }
        
        return dp[target];
    }
};

// 1 0 0 0 0

// 1: 1 1 1 1 1
// 2: 1 1 2 2 3
// 3: 1 1 2 3 4

// 1, 1, 1
// 1, 2
// 3

// 1 1 2 4 7