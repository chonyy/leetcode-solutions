class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        // take nums[r] as pivot
        // swap all num smaller than pivot to left
        // swap nums[r] to nums[pivot]
        int pivot = nums[r];
        int swapIdx = l;
        for (int i = l; i < r; i ++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[swapIdx]);
                swapIdx ++;
            }
        }

        // get get from r - swawpidx + 1
        swap(nums[swapIdx], nums[r]);
        int curK = r - swapIdx + 1;
        // cout << swapIdx << endl;

        // recurse
        if (curK == k) {
            return nums[swapIdx];
        }
        else if (curK > k) { // search right
            return quickSelect(nums, swapIdx + 1, r, k);
        }
        else { // search left
            return quickSelect(nums, l, swapIdx - 1, k - curK);
        }
    }
};
