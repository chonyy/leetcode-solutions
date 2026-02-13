class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);

        vector<int> temp;
        vector<vector<int>> res;

        backtrack(temp, res, used, nums, n);

        return res;
    }

    void backtrack(vector<int>& temp, vector<vector<int>>& res, vector<bool>& used, vector<int>& nums, int remain) {
        if (remain == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            temp.push_back(nums[i]);

            backtrack(temp, res, used, nums, remain-1);

            used[i] = false;
            temp.pop_back();
        }
    }
};