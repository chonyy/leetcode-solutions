class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for(int i = 0; i < n; i ++) {
            int num = nums[i];

            if(i < n-1 && num == nums[i+1]) {
                num *= 2;
                nums[i + 1] = 0;
            }

            if(num != 0) {
                nums[i] = 0;
                nums[j] = num;
                j ++;
            }
        }

        return nums;
    }
};