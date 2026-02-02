class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while (l < r) {
            int mid = l + (r - l) / 2;
            int num = nums[mid];

            if (num == target) {
                return mid;
            }

            bool curLeftPortion = num < nums[l];
            bool targetLeftPortion = target < nums[l];

            if (num < target) {
                // same portion: go right
                // different portion: go left
                if (curLeftPortion == targetLeftPortion) {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            else { // num > target
                // same: go left
                // different: got right
                if (curLeftPortion == targetLeftPortion) {
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

// 4,5,6,7,0,1,2
// l.          r
//       m

// num = 7
// target = 0;

// num > target

// 0,1,2,4,5,6,7


// 2,4,5,6,7.0,1
// target = 7

// l.          r

// m = 6
// mid < target

// 5 6 7 0 1 2 3
// l.          r
//       m

// target = 7
// mid = 0

// mid < target