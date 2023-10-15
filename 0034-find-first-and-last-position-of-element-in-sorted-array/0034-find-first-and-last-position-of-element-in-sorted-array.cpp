class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower(nums, target);
        int high = upper(nums, target);
        
        return {low, high};
    }
    
    int lower(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        int res = -1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                res = mid;
                r = mid;
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return res;
    }
    
    int upper(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        int res = -1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                res = mid;
                l = mid + 1;
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        
        return res;
    }
};