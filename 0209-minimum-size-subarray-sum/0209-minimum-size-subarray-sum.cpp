class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int res = INT_MAX;

        while (r < n) {
            sum += nums[r];

            while (sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l];
                l ++;
            }

            r ++;
        }

        return res == INT_MAX ? 0 : res;
    }
};