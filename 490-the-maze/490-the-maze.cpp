class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows;
    int cols;
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        rows = maze.size();
        cols = maze[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        
        visited[start[0]][start[1]]= true;
        q.push({start[0], start[1]});
        
        int steps = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                int row = cur.first;
                int col = cur.second;
                
                for(auto& dir : dirs) {
                    int newRow = row;
                    int newCol = col;
                    while(maze[newRow][newCol] == 0) {
                        newRow += dir[0];
                        newCol += dir[1];
                        
                        if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                            break;
                        }
                    }
                    newRow -= dir[0];
                    newCol -= dir[1];
                    
                    if(visited[newRow][newCol]) {
                        continue;
                    }
                    if(newRow == destination[0] && newCol == destination[1]) {
                        return true;
                    }
                    
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
            steps ++;
        }
        
        return false;
    }
};