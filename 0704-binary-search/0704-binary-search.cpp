class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int cur = nums[mid];
            if(cur == target) {
                return mid;
            }
            else if(cur < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        
        return -1;
    }
};