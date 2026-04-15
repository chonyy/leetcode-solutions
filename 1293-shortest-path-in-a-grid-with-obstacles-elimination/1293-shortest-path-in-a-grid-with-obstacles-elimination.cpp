class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (rows == 1 && cols == 1) {
            return 0;
        }

        vector<vector<int>> obstacles(rows, vector<int>(cols, -1));
        queue<vector<int>> q;
        q.push({0, 0, k});

        int path = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i ++) {
                auto& cur = q.front();
                int r = cur[0];
                int c = cur[1];
                int obs = cur[2];
                q.pop();

                for (auto& dir : dirs) {
                    int newR = r + dir[0];
                    int newC = c + dir[1];

                    // check for invalid
                    if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                        continue;
                    }

                    // check for visited with more ops
                    if (obstacles[newR][newC] >= obs) {
                        continue;
                    }

                    // check for result
                    if (newR == rows - 1 && newC == cols - 1) {
                        return path;
                    }

                    // obstacles or not, visit
                    if (grid[newR][newC] == 1) {
                        if (obs > 0) {
                            q.push({newR, newC, obs - 1});
                            obstacles[newR][newC] = obs - 1;
                        }
                    }
                    else {
                        q.push({newR, newC, obs});
                        obstacles[newR][newC] = obs;
                    }
                }
            }

            path ++;
        }

        return -1;
    }
};