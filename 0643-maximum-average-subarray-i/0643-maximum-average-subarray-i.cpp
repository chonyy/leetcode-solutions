class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        double res = INT_MIN;
        double sum = 0;

        while (r < n) {
            if (r - l == k) {
                sum -= nums[l];
                l ++;
            }

            sum += nums[r];
            if ((r - l + 1) == k) {
                res = max(res, sum / k);
            }
            r ++;
        }

        return res;
    }
};