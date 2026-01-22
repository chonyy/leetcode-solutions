class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 1);
        vector<int> suffixSum(n, 1);

        int j = n - 2;
        for (int i = 1; i < n; i ++ ) {
            prefixSum[i] = prefixSum[i-1] * nums[i-1];
            suffixSum[j] = suffixSum[j+1] * nums[j+1];
            j --;
        }

        vector<int> res(n);
        for (int i = 0 ; i < n; i ++) {
            res[i] = prefixSum[i] * suffixSum[i];
        }

        return res;
    }
};

// 1 2 3 4
// 1 1 2 6
// 24 12 4 1