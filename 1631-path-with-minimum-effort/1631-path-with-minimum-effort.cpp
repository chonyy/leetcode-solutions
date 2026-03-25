class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp); // effort, row, col 

        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));

        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            int effort = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();

            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }

            if (efforts[r][c] != INT_MAX && efforts[r][c] <= effort) {
                continue;
            }
            efforts[r][c] = effort;

            for (auto& dir : dirs) {
                int newR = r + dir[0];
                int newC = c + dir[1];

                // boundary check
                if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                    continue;
                }

                int diff = abs(heights[newR][newC] - heights[r][c]);
                int newEffort = max(effort, diff);

                pq.push({newEffort, newR, newC});
            }
        }

        return -1;
    }
};