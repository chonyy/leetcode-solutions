class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> res(n, -1);
        
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            while(!stk.empty() && num > nums[stk.top()]) {
                res[stk.top()] = num;
                stk.pop();
            }
            stk.push(i);
        }
        
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            while(!stk.empty() && num > nums[stk.top()]) {
                res[stk.top()] = num;
                stk.pop();
            }
            stk.push(i);
        }
        
        return res;
    }
};