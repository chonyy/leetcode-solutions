class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // elevation, row, col
        int n = grid.size();

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({0, 0, 0});
        visited[0][0] = true;
        int res = grid[0][0];

        // pop pq
        // always pick the lowest
        // keep track of last
        while (!pq.empty()) {
            int elevation = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            
            pq.pop();
            res = max(res, elevation);

            if (r == n-1 && c == n-1) {
                return res;
            }
            
            for (auto& dir : dirs) {
                int newR = r + dir.first;
                int newC = c + dir.second;

                if (newR < 0 || newR >= n || newC < 0 || newC >= n) {
                    continue;
                }

                if (visited[newR][newC]) {
                    continue;
                }

                visited[newR][newC] = true;
                pq.push({grid[newR][newC], newR, newC});
            }
        }

        return -1;
    }
};