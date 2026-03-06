class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r = 0;
        int l = 0;
        int n = nums.size();
        int minLen = INT_MAX;
        int sum = 0;

        while (r < n) {
            // keep track of current sum
            sum += nums[r];

            // while sum >= target, keep track of result
            // move left pointer and subtract
            while (sum >= target) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                l ++;
            }

            r ++;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};