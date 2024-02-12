class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];
        int count = 0;
        
        for(int num : nums) {
            if(cur == num) {
                count ++;
            }
            else {
                count --;
            }
            
            if(count < 0) {
                count = 1;
                cur = num;
            }
        }
        
        return cur;
    }
};