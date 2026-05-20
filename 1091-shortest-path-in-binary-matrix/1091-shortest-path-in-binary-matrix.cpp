class Solution {
public:
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }

        vector<vector<int>> copy = grid;
        int rows = grid.size();
        int cols = grid[0].size();

        copy[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto cur = q.front();
            int r = cur.first;
            int c = cur.second;
            q.pop();

            if (r == rows - 1 && c == cols - 1) {
                return copy[r][c];
            }

            for (auto& dir : dirs) {
                int newR = r + dir[0];
                int newC = c + dir[1];
                int newCost = copy[r][c] + 1;

                if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                    continue;
                }

                if (copy[newR][newC] != 0) {
                    continue;
                }

                copy[newR][newC] = newCost;
                q.push({newR, newC});
            }
        }

        return -1;
    }
};