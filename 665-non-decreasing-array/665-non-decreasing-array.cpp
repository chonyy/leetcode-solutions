class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int wrong = 0;
        int n = nums.size();

        for(int i = 1; i < n; i ++) {
            if(nums[i] < nums[i-1]) {
                if(wrong) {
                    return false;
                }
                
                wrong ++;
                if(i > 1 && nums[i] < nums[i-2]) {
                    nums[i] = nums[i-1];
                }
                else {
                    nums[i-1] = nums[i];
                }
            }
        }
    
        return wrong <= 1;
    }
};