class Solution {
public:
    int trap(vector<int>& height) {
        int highest = INT_MIN;
        int highPos = 0;
        int n = height.size();
        for(int i = 0; i < n; i ++) {
            int h = height[i];
            if(h > highest) {
                highest = h;
                highPos = i;
            }
        }
        
        int cur = 0;
        int curMax = 0;
        int water = 0;
        while(cur < highPos) {
            int h = height[cur];
            if(h > curMax) {
                curMax = h;
            }
            else {
                water += curMax - h;
            }
            cur ++;
        }
        
        cur = n-1;
        curMax = 0;
        
        while(cur > highPos) {
            int h = height[cur];
            if(h > curMax) {
                curMax = h;
            }
            else {
                water += curMax - h;
            }
            cur --;
        }
        
        return water;
    }
};