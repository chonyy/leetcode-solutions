class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long res = 0;
        long long prevIncrease = 0;
        long long prevMax = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i ++) {
            if (nums[i] + prevIncrease < prevMax) {
                long long need = prevMax - nums[i];
                prevIncrease = need;
            }
            prevMax = max(prevMax, nums[i] + prevIncrease);
        }

        return prevIncrease;
    }
};