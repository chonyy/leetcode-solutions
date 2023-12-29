class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        
        for(int i = 0; i < n; i ++) {
            if(seen.contains(nums[i])) {
                return true;
            }
            seen.insert(nums[i]);
        }
        
        return false;
    }
};