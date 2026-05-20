class Solution {
public:
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(rows, vector<bool>(cols));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({max(rows-1, cols-1), 1, 0, 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            int est = cur[0];
            int dist = cur[1];
            int r = cur[2];
            int c = cur[3];
            pq.pop();

            if (r == rows - 1 && c == cols - 1) {
                return dist;
            }

            if (visited[r][c]) {
                continue;
            }
            visited[r][c] = true;

            for (auto& dir : dirs) {
                int newR = r + dir[0];
                int newC = c + dir[1];
                int newEst = max(rows - newR - 1, cols - newC - 1);
                int newDist = dist + 1;

                if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                    continue;
                }

                if (grid[newR][newC] == 1) {
                    continue;
                }

                pq.push({newEst + newDist, newDist, newR, newC});
            }
        }

        return -1;
    }
};
