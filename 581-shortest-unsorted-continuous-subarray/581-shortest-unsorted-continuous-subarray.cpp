class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int curMax = INT_MIN;
        int curMin = INT_MAX;
        int end = -2;

        for(int i = 0; i < n; i ++) {
            int num = nums[i];

            curMax = max(curMax, num);
            if(num < curMax)
                end = i;
        }

        int begin = -1;
        for(int i = n - 1; i >= 0; i --) {
            int num = nums[i];

            curMin = min(curMin, num);
            if(num > curMin)
                begin = i;
        }

        return end - begin + 1;
    }
};