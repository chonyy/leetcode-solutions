class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodPairs = 0;
        long long total = 0;
        unordered_map<int,int> diffCount;
        int n = nums.size();

        for(int i = 0; i < n; i ++) {
            int diff = nums[i] - i;
            total += i;
            goodPairs += diffCount[diff];
            diffCount[diff] ++;
        }

        return total - goodPairs;
    }
};