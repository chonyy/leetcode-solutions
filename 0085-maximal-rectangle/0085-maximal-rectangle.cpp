class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> histogram(cols);

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (matrix[i][j] == '0') {
                    histogram[j] = 0;
                }
                else {
                    histogram[j] += 1;
                }
            }

            res = max(res, getMaxRectangle(histogram));
        }

        return res;
    }

    // 3 1 3 2 2
    // x

    // stack: 1
    // smallLeft: 1 2 1 2 3
    // smallRight: 1 4 1 2 1
    int getMaxRectangle(vector<int>& histogram) {
        stack<int> stk;
        int n = histogram.size();

        // find dist to first smaller to the left
        vector<int> smallLeft(n);
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && histogram[stk.top()] >= histogram[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                smallLeft[i] = i + 1;
            }
            else {
                smallLeft[i] = i - stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();
        // find dist to first smaller to the right
        vector<int> smallRight(n);
        for (int i = n-1; i >= 0; i --) {
            while (!stk.empty() && histogram[stk.top()] >= histogram[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                smallRight[i] = n - i;
            }
            else {
                smallRight[i] = stk.top() - i;
            }
            stk.push(i);
        }

        // max = max((smallLeft[i] + smallRight[i] - 1) * value)
        int res = 0;

        for (int i = 0; i < n; i ++) {
            int h = histogram[i];
            int width = smallLeft[i] + smallRight[i] - 1;
            res = max(res, h * width);
        }

        return res;
    }
};