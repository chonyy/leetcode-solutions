
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0;
        int globalMax = nums[0];
        int curMin = 0;
        int globalMin = nums[0];
        
        int total = 0;
        
        for(int num : nums) {
            curMax = max(num, curMax + num);
            globalMax = max(globalMax, curMax);
            curMin = min(num, curMin + num);
            globalMin = min(curMin, globalMin);            
            
            total += num;
        }
        cout << globalMax << endl;
        cout << globalMin << endl;
        return globalMax > 0 ? max(globalMax, total - globalMin) : globalMax;
    }
};