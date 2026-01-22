class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        vector<int> suffixSum(n);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i ++) {
            prefixSum[i] = nums[i] * prefixSum[i-1];
        }

        suffixSum[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i --) {
            suffixSum[i] = nums[i] * suffixSum[i+1];
        }

        vector<int> res(n);
        res[0] = suffixSum[1];
        res[n-1] = prefixSum[n-2];

        for (int i = 1; i < n-1; i ++) {
            res[i] = prefixSum[i-1] * suffixSum[i+1];
        }

        return res;
    }
};

// 1 2 3 4
// 1 2 6 24
// 24 24 12 4