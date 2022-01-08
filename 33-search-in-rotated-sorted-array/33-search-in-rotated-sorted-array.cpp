class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        int first = nums[0];
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int num = nums[mid];
            bool targetLarge = target >= first;
            bool isLarge = num >= first;
            
            if(num == target) {
                return mid;
            }
            else if(targetLarge == isLarge) {
                if(num < target) {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            else {
                if(num < target) {
                    r = mid;
                }
                else {
                    l = mid + 1;;
                }
            }
        }
        
        return -1;
    }
};