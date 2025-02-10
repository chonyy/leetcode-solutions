class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n = nums.size();

        for(int i = 0; i < n; i ++) {
            int num = nums[i];

            if(m.count(num)) {
                return {m[num], i};
            }

            int diff = target - num;
            m[diff] = i;
        }

        return {};
    }
};