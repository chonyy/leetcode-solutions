/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = getPeak(mountainArr);
        
        if (mountainArr.get(peak) == target) {
            return peak;
        }

        int l = 0;
        int r = peak;

        while (l < r) {
            int mid = l + (r - l) / 2;
            int num = mountainArr.get(mid);

            if (num == target) {
                return mid;
            }

            if (num < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        l = peak;
        r = mountainArr.length();

        while (l < r) {
            int mid = l + (r - l) / 2;
            int num = mountainArr.get(mid);

            if (num == target) {
                return mid;
            }

            if (num > target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return -1;
    }

    int getPeak(MountainArray &mountainArr) {
        int l = 0;
        int r = mountainArr.length();

        while (l < r) {
            int mid = l + (r - l) / 2;
            int num = mountainArr.get(mid);
        
            if (mountainArr.get(mid-1) < num && num > mountainArr.get(mid+1)) {
                return mid;
            }

            if (mountainArr.get(mid-1) < num) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return -1;
    }
};