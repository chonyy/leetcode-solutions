class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int low = lower(nums, target);
        int high = upper(nums, target);
        
        return {low, high};
    }
    
    int lower(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        if (l == n || nums[l] != target) {
            return -1;
        }

        return l;
    }
    
    int upper(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        if (l == 0 || nums[l-1] != target) {
            return -1;
        }
        
        return l - 1;
    }
};