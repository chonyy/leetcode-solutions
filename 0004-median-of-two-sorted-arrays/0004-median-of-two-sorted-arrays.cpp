class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // otherwise remainLen can go negative
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        int target = len / 2;

        int l = 0;
        int r = m;
        int idx1 = -1;
        int idx2 = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int remainLen = target - mid;

            int l1 = mid - 1 >= 0 ? nums1[mid-1] : INT_MIN;
            int r1 = mid < m ? nums1[mid] : INT_MAX;
            int l2 = remainLen - 1 >= 0 ? nums2[remainLen-1] : INT_MIN;
            int r2 = remainLen < n ? nums2[remainLen] : INT_MAX;

            // cout << l1 << " " << r1 << endl;
            // cout << l2 << " " << r2 << endl;

            // TODO: check for out of bound
            if (l1 <= r2 && l2 <= r1) {
                if (len % 2) {
                    return min(r1, r2);
                }
                else {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
            }

            if (l1 > r2) {
                // cout << "take left" << endl;
                r = mid;
            }
            else {
                // cout << "take right" << endl;
                l = mid + 1;
            }
        }

        return -1;
    }
};


// 1 2 3
//     m

// 4 5 
// r

// len = 5
// target = 2


// 1 2
//   i

// 3 4
//   j