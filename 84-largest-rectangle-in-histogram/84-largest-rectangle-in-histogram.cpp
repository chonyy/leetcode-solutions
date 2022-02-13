class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lessRight(n, n);
        vector<int> lessLeft(n, -1);
        
        for(int i = n-2; i >= 0; i --) {
            int p = i + 1;
            while(p < n && heights[p] > heights[i]) {
                p = lessRight[p];
            }
            lessRight[i] = p;
        }
        
        for(int i = 1; i < n; i ++) {
            int p = i - 1;
            while(p >= 0 && heights[p] >= heights[i]) {
                p = lessLeft[p];
            }
            lessLeft[i] = p;
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