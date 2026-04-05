class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diff;

        for (int i = 0; i < nums1.size(); i ++) {
            diff.push_back(nums1[i] - nums2[i]);
        }

        sort(diff.begin(), diff.end());

        int l = 0;
        int r = nums1.size() - 1;
        long long res = 0;

        // diff[i] + diff[j] > 0
        while (l < r) {
            int sum = diff[l] + diff[r];

            if (sum == 0) {
                l ++;
                continue;
            }

            if (sum > 0) {
                res += r - l;
                r --;
            }
            else {
                l ++;
            }
        }

        return res;
    }
};

// 5, 1
// 1, 3
// 4, -2

// nums1[i] - nums2[i] > nums2[j] - nums1[j]

// A[i] + A[j] > 0


// 1, 0
// 2, 3
// 6, 2
// 10, 1


// 1, 0
// 1, 2
// 4, 1
// 5, 3


// A  > -A

// 1, 10, 6, 2
//        i

// 1, 4, 1, 5


// 2 + 2 + 1


// 0, 6, 5, -3


// -3 0 5 6
//      i

// 2 + 2 + 1 


// A[i] + A[j] > 0

