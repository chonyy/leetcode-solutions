class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        unordered_map<int,int> prefix;
        prefix[0] = -1;
        int res = 0;

        for (int i = 0; i < n; i ++) {
            int num = nums[i];
            sum += num == 1 ? 1 : -1;

            if (prefix.contains(sum)) {
                res = max(res, i - prefix[sum]);
            }

            if (!prefix.contains(sum)) {
                prefix[sum] = i;
            }
        }

        return res;
    }
};