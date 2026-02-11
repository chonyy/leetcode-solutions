class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        // cout << l << " " << r << endl;
        int last = nums[r];
        int pivot = l;

        for (int i = l; i < r; i ++) {
            if (nums[i] < last) {
                swap(nums[pivot], nums[i]);
                pivot ++;
            }
        }

        swap(nums[pivot], nums[r]);

        int curK = r - pivot + 1;
        // cout << curK << endl;

        if (curK == k) {
            return nums[pivot];
        }
        else if (curK > k) {
            return quickSelect(nums, pivot+1, r, k);
        }
        else {
            return quickSelect(nums, l, pivot-1, k - curK);
        }
    }
};