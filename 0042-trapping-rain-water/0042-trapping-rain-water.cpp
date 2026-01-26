class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[0];
        int rightMax = height[r];

        while (l < r) {
            if (leftMax < rightMax) {
                l ++;
                leftMax = max(height[l], leftMax);
                res += leftMax - height[l];
            }
            else {
                r --;
                rightMax = max(height[r], rightMax);
                res += rightMax - height[r];
            }

            // cout << l << " " << r << endl;
            // cout << leftMax << " " << rightMax << endl;
            // cout << res << endl;
            // cout << endl;
        }

        return res;
    }
};

// keep track of max height
// water = water += maxHeight - curHeight
// conclude when curHeight >= maxHeight
// res = max water


// 0,1,0,2,1,0,1,3,2,1,2,1
//               i

// maxHeight = 3
// curWater = 0
// res = 4