class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // guranteed one element, no need for boundary check

        int res = nums[0];
        int curMax = nums[0];

        for (int i = 1; i < nums.size(); i ++) {
            curMax = max(nums[i], curMax + nums[i]);
            res = max(res, curMax);
        }

        return res;
    }
};


// -2,1,-3,4,-1,2,1,-5,4
//                     i

// res = 6
// curMax = 5

// max(4, -2 + 4)
