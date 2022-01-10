class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int curZeros = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;
        
        while(r < n) {
            curZeros += nums[r] == 0;
            
            while(curZeros > k) {
                curZeros -= nums[l] == 0;
                l ++;
            }
            
            ans = max(ans, r - l + 1);
            r ++;
        }
        
        return ans;
    }
};