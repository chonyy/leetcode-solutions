class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lessRight(n, n);
        vector<int> lessLeft(n, -1);
        
        stack<int> stk;
        
        for(int i = 0; i < n; i ++) {
            int h = heights[i];
            while(!stk.empty() && h < heights[stk.top()]) {
                lessRight[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        stk = {};
        
        for(int i = n-1; i >= 0; i --) {
            int h = heights[i];
            while(!stk.empty() && h < heights[stk.top()]) {
                lessLeft[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        int maxArea = 0;
        for(int i = 0; i < n; i ++) {
            int h = heights[i];
            int width = lessRight[i] - lessLeft[i] - 1;
            maxArea = max(maxArea, h * width);
        }
        
        return maxArea;
    }
};