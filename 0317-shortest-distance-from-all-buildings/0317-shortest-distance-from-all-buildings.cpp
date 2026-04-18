class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int shortestDistance(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        int emptyLandVal = 0;

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (grid[i][j] == 1) {
                    bfs(grid, dist, i, j, emptyLandVal);
                    emptyLandVal --;
                }
            }
        }

        int res = INT_MAX;

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (grid[i][j] == emptyLandVal) {
                    res = min(res, dist[i][j]);
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }

    // reuse input grid and track dist in negative
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dist, int r, int c, int emptyLandVal) {
        queue<pair<int,int>> q;
        q.push({r, c});
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i ++) {
                int curR = q.front().first;
                int curC = q.front().second;
                q.pop();

                for (auto& dir : dirs) {
                    int newR = curR + dir[0];
                    int newC = curC + dir[1];

                    if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                        continue;
                    }

                    if (grid[newR][newC] != emptyLandVal) {
                        continue;
                    }

                    grid[newR][newC] --;
                    dist[newR][newC] += steps;
                    q.push({newR, newC});
                }
            }
            steps ++;
        }
    }
};