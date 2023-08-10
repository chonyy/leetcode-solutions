class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            bool curLarge = nums[mid] >= nums[l];
            bool targetLarge = target >= nums[l];
            
            if(nums[mid] == target) {
                return mid;
            }
            
            if(curLarge == targetLarge) {
                if(target >= nums[mid]) {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            else {
                if(target >= nums[mid]) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        
        return -1;
    }
};