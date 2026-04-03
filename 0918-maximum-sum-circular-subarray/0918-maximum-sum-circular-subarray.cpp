class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = nums[0];
        int globalMax = curMax;
        int curMin = nums[0];
        int globalMin = curMin;

        int n = nums.size();
        int total = curMax;

        for (int i = 1; i < n; i ++) {
            int num = nums[i];
            curMax = max(curMax + num, num);
            globalMax = max(globalMax, curMax);
            curMin = min(curMin + num, num);
            globalMin = min(globalMin, curMin);
            total += num;
        }

        // total - globalMin: in the middle of ciruclar
        // globalMax: normal array
        // edge case: all negative

        return globalMax < 0 ? globalMax : max(globalMax, total - globalMin);
    }
};