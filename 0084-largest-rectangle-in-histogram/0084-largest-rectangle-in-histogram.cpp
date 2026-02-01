class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> stk; // startIdx, height
        int res = 0;

        for (int i = 0; i < n; i ++) {
            int h = heights[i];
            int popCount = 0;
            int start = i;
            // pop all elemetns larger
            // keep trace of pop count
            while(!stk.empty() && stk.top().second > h) {
                int startIdx = stk.top().first;
                int prevHeight = stk.top().second;
                int width = i - startIdx;
                int rec = width * prevHeight;

                res = max(res, rec);
                start = startIdx;
                stk.pop();
            }

            // use pop count of new startIdx
            stk.push({start, h});
        }

        while (!stk.empty()) {
            int startIdx = stk.top().first;
            int prevHeight = stk.top().second;
            int width = n - startIdx;
            int rec = width * prevHeight;

            res = max(res, rec);
            stk.pop();
        }
        
        return res;
    }
};