class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // when mid > mid+1, go left
        // when mid < mid+1, go right
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            // cout << l << " " << r << endl;

            if (nums[mid] > nums[mid+1]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};


// 1 2 3 1
// l.  r

// l = 2
// r = 2
// mid = 1