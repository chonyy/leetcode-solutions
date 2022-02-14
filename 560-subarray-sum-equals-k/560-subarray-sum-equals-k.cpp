class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        seen[0] = 1;
        int curSum = 0;
        int count = 0;
        
        for(int num : nums) {
            curSum += num;
            count += seen[curSum - k];
            seen[curSum] ++;
        }
        
        return count;
    }
};