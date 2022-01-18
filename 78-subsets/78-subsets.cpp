class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int cur) {
        res.push_back(temp);
        if(cur == nums.size()) {
            return;
        }          
        
        for(int i = cur; i < nums.size(); i ++) {
            temp.push_back(nums[i]);
            backtrack(res, temp, nums, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        backtrack(res, temp, nums, 0);
        return res;
    }
};