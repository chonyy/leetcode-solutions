class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();

        vector<int> shorterRight(n);
        // from left to right, get distance to next shorter
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                // cout << stk.top() << " shorter right " << i - stk.top() << endl;;
                shorterRight[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            shorterRight[stk.top()] = n - stk.top();
            stk.pop();
        }

        vector<int> shorterLeft(n);
        // from right to left, get distance to next shorter
        for (int i = n -1; i >= 0; i --) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                shorterLeft[stk.top()] = stk.top() - i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            shorterLeft[stk.top()] = stk.top() - (-1);
            stk.pop();
        }

        // res = max(height * (shortLeft + shortRight - 1))
        int res = 0;

        for (int i = 0; i < n; i ++) {
            int width = shorterLeft[i] + shorterRight[i] - 1;
            // cout << heights[i] << " " << width << " " << shorterLeft[i] << " " << shorterRight[i] << " " << endl;
            res = max(res, width * heights[i]);
        }

        return res;
    }
};