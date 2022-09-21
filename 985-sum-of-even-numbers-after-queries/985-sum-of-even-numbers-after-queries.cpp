class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        
        for(int num : nums) {
            if(num % 2 == 0) 
                sum += num;
        }
        
        vector<int> res;
        int n = nums.size();
        
        for(auto q : queries) {
            int index = q[1];
            int val = q[0];
            
            if(nums[index] % 2 == 0) {
                sum -= nums[index];
            }
            nums[index] += val;
            
            if(nums[index] % 2 == 0) {
                sum += nums[index];
            }
            res.push_back(sum);
        }
        
        return res;
    }
};