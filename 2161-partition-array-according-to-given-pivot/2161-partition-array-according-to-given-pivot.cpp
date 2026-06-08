class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lessIdx = 0;
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i ++) {
            if (nums[i] < pivot) {
                res[lessIdx] = nums[i];
                lessIdx ++;
            }
        }

        int greatIdx = n-1;
        for (int i = n - 1; i >= 0; i --) {
            if (nums[i] > pivot) {
                res[greatIdx] = nums[i];
                greatIdx --;
            }
        }

        while (lessIdx <= greatIdx) {
            res[lessIdx] = pivot;
            lessIdx ++;
        }

        return res;
    }
};