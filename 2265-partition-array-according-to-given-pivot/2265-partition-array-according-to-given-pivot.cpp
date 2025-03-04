class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int insert1 = 0;
        int insert2 = n - 1;

        int less = 0;
        vector<int> res(n, pivot);

        for(int i = 0; i < n; i ++) {
            int ri = n - 1 - i;

            if(nums[i] < pivot) {
                res[insert1] = nums[i];
                insert1 ++;
            }

            if(nums[ri] > pivot) {
                res[insert2] = nums[ri];
                insert2 --;
            }
        }

        return res;
    }
};