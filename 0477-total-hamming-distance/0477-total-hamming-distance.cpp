class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < 31; i ++) {
            int zeros = 0;
            int ones = 0;
            int mask = 1 << i;

            for (int num : nums) {
                zeros += (num & mask) == 0;
                ones += (num & mask) > 0;
            }

            sum += zeros * ones;
        }

        return sum;
    }
};