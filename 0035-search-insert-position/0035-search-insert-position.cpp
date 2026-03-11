class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // lower bound
        int l = 0;
        int r = nums.size();
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            int num = nums[mid];
            
            if (num == target) {
                return mid;
            } else if (num < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};