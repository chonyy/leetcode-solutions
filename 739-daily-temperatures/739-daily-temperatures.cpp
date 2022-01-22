class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i ++) {
            int temp = temperatures[i];
            while(!stk.empty() && temp > temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        
        return res;
    }
};