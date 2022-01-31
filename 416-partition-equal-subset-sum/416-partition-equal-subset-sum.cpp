class Solution {
public:
    bool solve(vector<int>& nums, int target, int idx, vector<vector<int>>& memo) {
        if(target < 0)
            return false;
        if(target == 0)
            return true;
        if(idx == nums.size()) 
            return false;
        if(memo[idx][target] != -1)
            return memo[idx][target];
        
        bool res = solve(nums, target-nums[idx], idx+1, memo) || solve(nums, target, idx+1, memo);
        
        return memo[idx][target] = res;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        
        for(int num : nums) {
            sum += num;
        }
        int target = sum / 2;
        if(sum % 2)
            return false;
        vector<vector<int>> memo(n+1, vector<int>(target+1, -1));
        
        return solve(nums, target, 0, memo);
    }
};