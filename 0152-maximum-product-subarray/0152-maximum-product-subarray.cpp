class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int res = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i ++) {
            int num = nums[i];
            if (num == 0) {
                curMax = 1;
                curMin = 1;
                res = max(res, 0);
                continue;
            }

            if (num < 0) {
                swap(curMax, curMin);
            }

            curMax = max(curMax * num, num);
            curMin = min(curMin * num, num);
            // cout << curMax << " " << curMin << endl;
            res = max(res, curMax);
        }

        return res;
    }
};

// 2,3,-2,4, 5

// 2 6 6
// 2 6 -24