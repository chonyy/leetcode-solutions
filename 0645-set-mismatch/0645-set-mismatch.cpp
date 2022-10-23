class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        
        for(int num : nums) {
            if(nums[abs(num)-1] < 0)
                res[0] = abs(num);
            else
                nums[abs(num) - 1] *= -1;
        }
        
        for(int i = 0 ; i < nums.size(); i ++) {
            if(nums[i] > 0) {
                res[1] = i + 1;
            }
        }
        
        return res;
    }
};