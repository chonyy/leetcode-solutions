class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prevTwo = 0;
        int prevOne = 0;
        
        for(int i = 0; i < n; i ++) {
            int temp = max(prevTwo + nums[i], prevOne);
            prevTwo = prevOne;
            prevOne = temp;
        }
        
        return prevOne;
    }
};