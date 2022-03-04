class Solution {
public:
    int shortest;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows, cols;
    
    int bfs(vector<vector<int>>& grid, queue<pair<pair<int,int>, int>>& q, vector<vector<int>>& visited) {
        int steps = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front(); 
                q.pop();
                int row = cur.first.first;
                int col = cur.first.second;
                int curStep = cur.second;
                
                // cout << row << " " << col << endl;

                for(auto& dir : dirs) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    
                    // cout << newRow << " " << newCol << endl;

                    // find destination
                    if(newRow == rows -1 && newCol == cols-1)
                        return steps;

                    // invalid walk
                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
                        continue;
                    if(visited[newRow][newCol] != -1 && visited[newRow][newCol] >= curStep) {
                        continue;
                    }
                    
                    // need update
                    // eliminate obstacle
                    if(grid[newRow][newCol] == 1) {
                        if(curStep > 0) {
                            q.push({{newRow, newCol}, curStep-1});
                            visited[newRow][newCol] = curStep - 1;
                        }
                        else {
                            continue;
                        }
                    }
                    else {
                        q.push({{newRow, newCol}, curStep});
                        visited[newRow][newCol] = curStep;
                    }
                }
            }
            steps ++;
        }
        
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<pair<pair<int,int>, int>> q;
        q.push({{0, 0}, k});
        
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        
        if(rows == 1 && cols == 1)
            return 0;
        
        visited[0][0] = k;
        
        return bfs(grid, q, visited);
    }
};