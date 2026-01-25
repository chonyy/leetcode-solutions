class Solution {
public:
    void twoSum(int i, vector<int>& nums, vector<vector<int>>& res) {
        int l = i + 1;
        int r = nums.size() - 1;
        int target = -nums[i];

        while (l < r) {
            int curSum = nums[l] + nums[r];
            
            if (curSum == target) {
                res.push_back({nums[i] , nums[l], nums[r]});
                l ++;
                r --;

                while(nums[l] == nums[l-1] && l < r) {
                l ++;
                }
                while(nums[r] == nums[r+1] && l < r) {
                    r --;
                }
            }
            else if (curSum < target) {
                l ++;
            }
            else {
                r --;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            twoSum(i, nums, res);
        }

        return res;
    }
};
