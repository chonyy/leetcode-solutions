class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);

        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            int h = heights[i];
            
            while (!stk.empty() && h < heights[stk.top()]) {
                rightMost[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n-1; i >= 0; i --) {
            int h = heights[i];
            
            while (!stk.empty() && h < heights[stk.top()]) {
                leftMost[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int res = 0;

        for (int i = 0; i < n; i ++) {
            int width = rightMost[i] - leftMost[i] - 1;
            int rec = heights[i] * width;
            res = max(rec, res);
        }

        return res;
    }
};