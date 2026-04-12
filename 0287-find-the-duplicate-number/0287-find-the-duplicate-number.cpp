class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i ++) {
            int num = abs(nums[i]) - 1;
            if (nums[num] < 0) {
                return num + 1;
            }
            nums[num] *= -1;
        }

        return -1;
    }
};

// 1 2 3 4 5 = 15
// 1 3 4 2 2 = 12