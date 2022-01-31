class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int num : nums) {
            sum += num;
        }
        int target = sum / 2;
        if(sum % 2)
            return false;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; i ++) {
            int num = nums[i-1];
            vector<bool> temp(target+1, false);
            for(int j = 1; j <= target; j ++) {
                int need = j - num;
                temp[j] = dp[j];
                if(need >= 0) {
                    temp[j] = temp[j] | dp[need];
                }
            }
            swap(dp, temp);
        }
        
        return dp[target];
    }
};