class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int globalMax = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];
        
        for(int i = 1; i < n; i ++) {
            int num = nums[i];
            if(num < 0) {
                swap(curMax, curMin);
            }
            
            curMax = max(num, curMax * num);
            curMin = min(num, curMin * num);
            globalMax = max(curMax, globalMax);
        }
        
        return globalMax;
    }
};