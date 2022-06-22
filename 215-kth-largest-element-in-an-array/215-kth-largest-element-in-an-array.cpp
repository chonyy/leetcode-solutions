class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }
    
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int pivot = l;
        
        for(int i = l; i < r; i ++) {
            if(nums[i] <= nums[r]) {
                swap(nums[pivot++], nums[i]);
            }
        }
        swap(nums[pivot], nums[r]);
        
        int diff = r - pivot + 1;
        if(diff == k) {
            return nums[pivot];
        }
        else if(diff < k) {
            return quickSelect(nums, l, pivot-1, k-diff);
        }
        else {
            return quickSelect(nums, pivot+1, r, k);
        }
    }
};