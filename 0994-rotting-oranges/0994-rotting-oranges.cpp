class Solution {
public:
    int rows;
    int cols;
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int minute = 1;

        // store all rottens in queue for bfs
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh ++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        if (q.empty()) {
            return -1;
        }

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i ++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (auto& dir : dirs) {
                    int newR = r + dir.first;
                    int newC = c + dir.second;
                    
                    if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                        continue;
                    }

                    if (grid[newR][newC] != 1) {
                        continue;
                    }

                    // rot it
                    grid[newR][newC] = 2;
                    fresh --;

                    q.push({newR, newC});
                }
            }

            if (fresh == 0) {
                return minute;
            }

            minute ++;
        }

        return -1;
    }
};

// 2 1 1
// 0 1 1
// 1 0 1