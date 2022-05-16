class Solution {
public:
    vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.size();
        
        if(grid[0][0] == 1 || grid[rows-1][cols-1] == 1)
            return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int distance = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                int row = cur.first;
                int col = cur.second;
                if(row == rows-1 && col == cols-1) {
                    return distance;
                }
                
                for(auto dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    
                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                        continue;
                    }
                    
                    if(grid[newRow][newCol] == 1) {
                        continue;
                    }
                    
                    grid[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                } 
            }
            distance ++;
        }
        
        return -1;
    }
};