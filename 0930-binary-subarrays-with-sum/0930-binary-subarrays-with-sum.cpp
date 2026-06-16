class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int cur = 0;
        int res = 0;

        while (r < n) {
            cur += nums[r];
            while (l <= r && cur > goal) {
                cur -= nums[l];
                l ++;
            }

            res += r - l + 1;
            r ++;
        }

        return res;
    }
};