class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());

        perm(nums, used, temp, res);

        return res;
    }

    void perm(vector<int>& nums, vector<bool>& used, vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }

            if (used[i] == true) {
                continue;
            }

            used[i] = true;
            // cout << nums[i] << endl;
            temp.push_back(nums[i]);
            perm(nums, used, temp, res);
            temp.pop_back();
            used[i] = false;
        }
    }
};