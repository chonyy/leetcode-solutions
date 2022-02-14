class Solution {
public:
    int rows = 0;
    int cols = 0;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    int getArea(vector<vector<int>>& grid, int row, int col) {
        stack<pair<int,int>> stk;
        stk.push({row, col});
        grid[row][col] = 0;
        int area = 1;
        
        while(!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            
            for(auto& dir : dirs) {
                int newRow = cur.first + dir[0];
                int newCol = cur.second + dir[1];
                
                if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
                    continue;
                if(grid[newRow][newCol] == 0)
                    continue;
                
                grid[newRow][newCol] = 0;
                stk.push({newRow, newCol});
                area ++;
            }
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == 0)
                    continue;
                int area = getArea(grid, i, j);
                ans = max(ans, area);
            }
        }
        
        return ans;
    }
};