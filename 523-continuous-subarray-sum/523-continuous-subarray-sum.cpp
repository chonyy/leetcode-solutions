class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> prevSum;
        int n = nums.size();
        
        prevSum[0] = -1;
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            sum += num;
            sum = sum % k;
            
            if(prevSum.count(sum)) {
                if(i - prevSum[sum] > 1) {
                    return true;                    
                }
            }
            else {
                prevSum[sum] = i;
            }
        }
        
        return false;
    }
};