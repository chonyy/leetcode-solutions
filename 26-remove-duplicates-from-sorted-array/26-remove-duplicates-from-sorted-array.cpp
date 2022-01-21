class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int outputIdx = 1;
        int n = nums.size();
        
        if(nums.size() == 0) {
            return 0;
        }
        
        for(int i = 1; i < n; i ++) {
            if(nums[i] != nums[i-1]) {
                nums[outputIdx] = nums[i];
                outputIdx ++;
            }
        }
        
        return outputIdx;
    }
};