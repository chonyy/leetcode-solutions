class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int r = n;
        int l = 0;

        while (l < r) {
            // cout << l << " " << r << endl;
            int mid = l +  (r - l) / 2;
            int num = nums[mid];
            
            if (num == target) {
                return mid;
            }
            else if (num > target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return -1;
    }
};