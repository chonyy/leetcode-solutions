class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& set, int idx, vector<int>& nums) {
        res.push_back(set);
        
        for(int i = idx; i < nums.size(); i ++) {
            if(i != idx && nums[i] == nums[i-1])
                continue;
            
            set.push_back(nums[i]);
            backtrack(res, set, i+1, nums);
            set.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> set;
        backtrack(res, set, 0, nums);
        return res;
    }
};