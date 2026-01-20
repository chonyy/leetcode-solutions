class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mem;
        int n = nums.size();

        for (int i = 0; i < n; i ++) {
            int num = nums[i];
            if(mem.count(target - num) != 0) {
                return {mem[target - num], i};
            }

            mem[num] = i;
        }

        return {};
    }
};