class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p1 = 0;
        int p2 = 0;
        int n = nums.size();
        int cur = 1;
        int ans = 0;
        
        if(k <= 1) {
            return 0;
        }
        
        while(p2 < n) {
            cur *= nums[p2];
            while(cur >= k) {
                cur /= nums[p1];
                p1 ++;
            }
            ans += p2 - p1 + 1;
            p2 ++;
        }

        return ans;
    }
};