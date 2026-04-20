class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        // min heap
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            auto& cur = pq.top();
            int effort = cur[0];
            int r = cur[1];
            int c = cur[2];
            pq.pop();

            if (visited[r][c]) {
                continue;
            }
            visited[r][c] = true;

            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }

            for (auto& dir : dirs) {
                int newR = r + dir[0];
                int newC = c + dir[1];

                if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                    continue;
                }

                int newEffort = max(effort, abs(heights[r][c] - heights[newR][newC]));

                pq.push({newEffort, newR, newC});
            }
        }

        return -1;
    }
};