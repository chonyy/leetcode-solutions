class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> cache;
        int n = nums.size();
        
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            if(cache.contains(num)) {
                return {cache[num], i};
            }
            
            cache[target - num] = i;
        }
        
        return {};
    }
};