class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        
        int res = 0;
        int odd = 0;

        while (r < n) {
            // add nums[r]
            odd += nums[r] % 2;

            // if larger than k, shift l, remove count, erase nums[l] if 0
            while (odd > k) {
                odd -= nums[l] % 2;
                l ++;
            }

            res += r - l + 1;
            r ++;
        }

        return res;
    }
};