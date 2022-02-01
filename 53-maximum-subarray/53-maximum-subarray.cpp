class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int globalSum = nums[0];
        
        for(int num : nums) {
            if(curSum < 0) {
                curSum = 0;
            }
        
            curSum += num;
            globalSum = max(globalSum, curSum);
        }
        
        return globalSum;
    }
};