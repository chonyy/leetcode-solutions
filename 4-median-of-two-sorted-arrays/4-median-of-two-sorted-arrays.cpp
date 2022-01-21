class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int target = len / 2;
        bool odd = len % 2;
        
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int n = nums1.size();
        int l = 0;
        int r = n;
        
        while(true) {
            int mid1 = l + (r-l) / 2;
            int mid2 = target - mid1;
            
            int l1 = mid1-1 >= 0 ? nums1[mid1-1] : INT_MIN;
            int r1 = mid1 < nums1.size() ? nums1[mid1] : INT_MAX;
            int l2 = mid2-1 >= 0 ? nums2[mid2-1] : INT_MIN;
            int r2 = mid2 < nums2.size() ? nums2[mid2] : INT_MAX;
            
            cout << l1 << " " << r1 << endl;
            cout << l2 << " " << r2 << endl;
            
            if(l1 <= r2 && l2 <= r1) {
                if(odd) {
                    return min(r1, r2);
                }
                else {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
            }
            else if(l1 > r2) {
                r = mid1;
            }
            else {
                l = mid1 + 1;
            }
        }
        
        return -1;
    }
};


// 1 3 5
// 2 4 6
    
// 1 2 3 4 5 6