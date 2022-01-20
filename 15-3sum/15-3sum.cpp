class Solution {
public:
    void check(vector<int>& nums, vector<vector<int>>& res, int target, int start, int end) {
        int l = start, r = end;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum == target) {
                res.push_back({-target, nums[l], nums[r]});
                
                while(l < r && nums[l] == nums[l+1]) {
                    l ++;
                }
                while(l < r && nums[r] == nums[r-1]) {
                    r --;
                }
                
                l ++;
                r --;
            }
            else if(sum > target) {
                r --;
            }
            else {
                l ++;
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        
        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            check(nums, res, -nums[i], i+1, n-1);
        }
        
        return res;
    }
};