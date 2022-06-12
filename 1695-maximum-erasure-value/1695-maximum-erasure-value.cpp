class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int l = 0, r = 0;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        
        while(r < n) {
            while(seen.find(nums[r]) != seen.end()) {
                sum -= nums[l];
                seen.erase(nums[l]);
                l ++;
            }
            sum += nums[r];
            ans = max(ans, sum);
            seen.insert(nums[r]);
            
            r ++;
        }
        
        return ans;
    }
};