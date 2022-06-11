class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int> seen;
        int curSum = 0;
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i ++) {
            curSum += nums[i];
            seen[curSum] = i;
            if(curSum == x) {
                ans = i +1;
                cout << "set" << endl;
            }
        }
        
        curSum = 0;
        
        seen[0] = -1;
        for(int i = n-1; i >= 0; i --) {
            curSum += nums[i];
            int target = x - curSum;
            if(seen.find(target) != seen.end()) {
                if(seen[target] >= i)
                    continue;
                ans = min(ans, n - i + seen[target] +1);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};