class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i ++) {
            if (i > maxReach) {
                return false;
            }

            int num = nums[i];
            maxReach = max(maxReach, i + num);

            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};

// 2,3,1,1,4
//   i

// keep track of maxReachIdx

// maxReach = 2

// maxReach = 1 + 3

// if maxReach >= num.size()-1
//     return true

// if get to anypoint that's larger than maxReach, return false