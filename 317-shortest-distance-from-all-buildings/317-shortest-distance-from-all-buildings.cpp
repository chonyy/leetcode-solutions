class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows;
    int cols;
    
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& distance, int row, int col, int count) {
        queue<pair<int,int>> q;
        q.push({row, col});
        int steps = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                // cout << cur.first << " " << cur.second << endl;
                
                for(auto& dir : dirs) {
                    int newRow = cur.first + dir[0];
                    int newCol = cur.second + dir[1];
                    
                    // boundary check
                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                        continue;
                    }
                    // count check
                    if(grid[newRow][newCol] != count)
                        continue;
                    
                    grid[newRow][newCol] = count - 1;
                    distance[newRow][newCol] += steps;
                    q.push({newRow, newCol});
                }
                
            }
            steps ++;
        }
        
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        int count = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        vector<vector<int>> distance(rows, vector<int>(cols));
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == 1) {
                    bfs(grid, distance, i, j, count);
                    count --;
                }
            }
        }
        
        int res = INT_MAX;
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == count) {
                    res = min(res, distance[i][j]);
                }
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};