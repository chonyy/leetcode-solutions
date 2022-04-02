/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    int n;
    vector<pair<vector<int>, char>> dirs = {{{-1, 0}, 'U'}, {{1, 0}, 'D'}, {{0, -1}, 'L'}, {{0, 1}, 'R'}}; 
    vector<char> oppos = {'D', 'U', 'R', 'L'};
    void dfs(vector<vector<int>>& grid, GridMaster& master, int row, int col) {
        // cout << row << " " << col << endl;
        
        if(row < 0 || row >= n || col < 0 || col >= n) {
            return;
        }
        
        if(master.isTarget()) {
            // cout << "target " << row << " " << col << endl;
            grid[row][col] = 2;
            return;
        }
        
        grid[row][col] = 1;
        for(int i = 0; i < 4; i ++) {
            auto& dir = dirs[i];
            auto& dirr = dir.first;
            auto& dirChar = dir.second;
            int newRow = row + dirr[0];
            int newCol = col + dirr[1];
            
            if(!master.canMove(dirChar)) {
                // cout << "cant move " << dirChar << endl; 
                grid[newRow][newCol] = 0;
                continue;
            }
            if(grid[newRow][newCol] != -2) {
                continue;
            }
            
            // cout << "move " << dirChar << endl;
            master.move(dirChar);
            dfs(grid, master, newRow, newCol);
            
            master.move(oppos[i]);
        }
    }
    
    int findShortestPath(GridMaster &master) {
        n = 2000;
        vector<vector<int>> grid(n, vector<int>(n, -2));
        grid[1000][1000] = -1;
        dfs(grid, master, 1000, 1000);
        
        queue<pair<int,int>> q;
        q.push({1000, 1000});
        int steps = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                int row = cur.first;
                int col = cur.second;
                // cout << row << " " << col << endl;
                for(auto& dir : dirs) {
                    auto& dirr = dir.first;
                    int newRow = row + dirr[0];
                    int newCol = col + dirr[1];
                    
                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) {
                        continue;
                    }
                    if(grid[newRow][newCol] == 2) {
                        return steps;
                    }
                    
                    if(grid[newRow][newCol] != 1) {
                        continue;
                    }
                    
                    grid[newRow][newCol] = 0;
                    q.push({newRow, newCol});
                }
            }
            steps ++;
        }
        
        return -1;
    }
};

// 0 0 -1
// 1 1  1
// 2 0 0 