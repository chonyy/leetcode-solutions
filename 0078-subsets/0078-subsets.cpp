class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;

        backtrack(temp, res, nums, 0);

        return res;
    }

    void backtrack(vector<int>& temp, vector<vector<int>>& res, vector<int>& nums, int cur) {
        res.push_back(temp);

        if (cur == nums.size()) {
            return;
        }

        for (int i = cur; i < nums.size(); i ++) {
            temp.push_back(nums[i]);
            backtrack(temp, res, nums, i+1);
            temp.pop_back();
        }
    }
};