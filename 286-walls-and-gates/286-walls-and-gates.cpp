class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows;
    int cols;
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        
        rows = rooms.size();
        cols = rooms[0].size();
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // BFS
        int step = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                for(auto dir : dirs) {
                    int newRow = cur.first + dir[0];
                    int newCol = cur.second + dir[1];
                    
                    // bondary check
                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                        continue;
                    }

                    if(rooms[newRow][newCol] != INT_MAX) {
                        continue;
                    }
                    
                    rooms[newRow][newCol] = min(rooms[newRow][newCol], step);
                    q.push({newRow, newCol});
                }
            }
            step ++;
        }
    }
};