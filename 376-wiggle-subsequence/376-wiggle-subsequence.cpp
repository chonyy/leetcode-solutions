class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 1;
        int down = 1;
        int n = nums.size();
        
        for(int i = 1; i < n; i ++) {
            if(nums[i] > nums[i-1]) {
                up = down + 1;
            }
            if(nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }
        
        return max(up, down);
    }
};

// 1,17,5,10,13,15,10,5,16,8
//                         o
     
// up: 6
// down: 7