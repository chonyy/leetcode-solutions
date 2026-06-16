class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int res = 0;

        while (r < n) {
            sum += nums[r];

            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l];
                l ++;
            }

            res = max(res, r - l + 1);
            r ++;
        }

        return res;
    }
};

// 1,4,8,13
//   l
//     r


// sum = 12
// len = 2
// target = 16
// need = 4
// res = 2

// len = r - l + 1
// target = nums[r] * len
// need = target - sum
// shrink when need > k
// record ans = r - l + 1