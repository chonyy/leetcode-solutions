class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i ++) {
            int l = i + 1;
            int r = n - 1;
            int target = -nums[i];

            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            while (l < r) {
                int cur = nums[l]+ nums[r];

                if (cur == target) {
                    res.push_back({nums[i], nums[l], nums[r]});

                    while (l < n -1 && nums[l] == nums[l+1]) {
                        l ++;
                    }

                    while (r > 0 && nums[r] == nums[r-1]) {
                        r --;
                    }
                }

                if (cur < target) {
                    l ++;
                }
                else {
                    r --;
                }
            }
        }

        return res;
    }
};