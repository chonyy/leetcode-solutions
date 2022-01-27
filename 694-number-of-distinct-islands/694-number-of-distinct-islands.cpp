class Solution {
public:
    int rows;
    int cols;
    
    void dfs(vector<vector<int>>& grid, int row, int col, string& path, char cur) {
        if(row < 0 || row >= rows || col < 0 || col >= cols)
            return;
        if(grid[row][col] == 0)
            return;
        
        // cout << row << " " << col << endl;
        // cout << cur << endl;
        path += cur;
        grid[row][col] = 0;
        
        dfs(grid, row+1, col, path, 'd');
        dfs(grid, row-1, col, path, 'u');
        dfs(grid, row, col+1, path, 'r');
        dfs(grid, row, col-1, path, 'l');
        path += 'b';
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        unordered_set<string> seen;
        
        for(int i= 0 ; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == 1) {
                    string s = "";
                    dfs(grid, i, j, s, 's');
                    seen.insert(s);
                    cout << s << endl;
                }
            }
        }
        
        return seen.size();
    }
};

// 1 1 0
// 0 1 1 
// 0 0 0
// 1 1 1 
// 0 1 0