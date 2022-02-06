class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curReach = 0;
        int maxReach = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i ++) {
            maxReach = max(maxReach, i + nums[i]);
            
            if(i == curReach && i != n-1) {
                jumps ++;
                curReach = maxReach;
                maxReach = 0;
            }
        }        
        
        return jumps;
    }
};