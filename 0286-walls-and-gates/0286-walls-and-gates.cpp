class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        int cols = rooms[0].size();

        queue<pair<int,int>> q;
        
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // bfs
        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0 ; i < size; i ++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (auto& dir : dirs) {
                    int newR = r + dir[0];
                    int newC = c + dir[1];

                    // boundary check
                    if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
                        continue;
                    }

                    // visited check
                    if (rooms[newR][newC] != INT_MAX) {
                        continue;
                    }

                    // set and push to queue
                    rooms[newR][newC] = steps;
                    q.push({newR, newC});
                }
            }
            steps ++;
        }
    }
};