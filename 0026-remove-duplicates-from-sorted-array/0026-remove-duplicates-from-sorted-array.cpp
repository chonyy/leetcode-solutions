class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIdx = 1;
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != nums[i-1]) {
                nums[insertIdx] = nums[i];
                insertIdx ++;
            }
        }

        return insertIdx;
    }
};