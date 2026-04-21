class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = 0; i < n; i ++) {
            nums[n + i] <<= 10;
            nums[n + i] |= nums[i];
        }

        int allOnes = pow(2, 10) - 1;

        for (int i = 0; i < n; i ++) {
            int y = nums[n + i] >> 10;
            int x = nums[n + i] & allOnes;

            nums[2 * i] = x;
            nums[2 * i + 1] = y;
        }

        return nums;
    }
};