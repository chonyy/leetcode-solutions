class Solution {
public:
    int minDiff = INT_MAX;
    int res = 0;
    
    void find(vector<int>& nums, int start, int end, int target, int firstNum) {
        while(start < end) {
            int sum = nums[start] + nums[end];
            int diff = target - sum;
            // cout << firstNum << " " << nums[start] << " " << nums[end] << endl;
            // cout << target << endl;
            if(abs(diff) < minDiff) {
                minDiff = abs(diff);
                res = firstNum + sum;
            }
            
            // move pointer
            if(diff == 0) {
                break;
            }
            else if(diff > 0) {
                start ++;
            }
            else {
                end --;
            }
        }
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-2; i ++) {
            int lookFor = target - nums[i];
            find(nums, i+1, n-1, lookFor, nums[i]);
        }
        
        return res;
    }
};