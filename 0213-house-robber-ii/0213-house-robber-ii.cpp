class Solution {
public:
    int robb(vector<int>& nums) {
        int n = nums.size();
        int prevOne = 0;
        int prevTwo = 0;
        
        for(int i = 0; i < n; i ++) {
            int temp = max(prevTwo + nums[i], prevOne);
            prevTwo = prevOne;
            prevOne = temp;
        }
        
        return prevOne;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        
        
        vector<int> front(nums.begin(), nums.end()-1);
        vector<int> back(nums.begin()+1, nums.end());
        return max(robb(front), robb(back));
    }
};