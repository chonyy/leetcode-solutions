class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        
        int l = 0;
        int r = 0;
        int n = nums.size();
        int curSum = 0;
        int ans = INT_MAX;
        
        while(r < n) {
            curSum += nums[r];
            while(l <= r && curSum > sum - x) {
                curSum -= nums[l];
                    l ++;
            }
            if(curSum == sum - x) {
                ans = min(ans, n - (r - l + 1));
            }
            r ++;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};