class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while (l < r) {
            int mid = l + (r - l) / 2; // prevent overflow
            int num = nums[mid];
            // cout << l << " " << r << endl;

            // if num is target, return
            if (num == target  || nums[l] == target) {
                return true;
            }

            // if num is same as left num, can't determine left or right portion, move left pointer
            if (num == nums[l]) {
                l ++;
                continue;
            }

            // move left or right based on num and target portion
            bool numLeftPortion = num > nums[l];
            bool targetLeftPortion = target > nums[l];

            if (numLeftPortion == targetLeftPortion) { // same portion of array, regular binary search
                if (num < target) {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            else { // opposite of binary search
                if (num < target) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
        }

        return false;
    }
};