class Solution {
public:
    int rows, cols;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int hash(vector<vector<int>>& mat) {
        int res = 0;
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                int idx = i * cols + j;
                res |= mat[i][j] << idx;
            }
        }
        return res;
    }
    
    int toIdx(int row, int col) {
        return row * cols + col;
    }
    
    int flip(int mat, int row, int col) {
        int flipped = mat;
        // flip the idxx
        flipped ^= (1 << toIdx(row, col));
        
        // flip the neighbors
        for(auto& dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            
            if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) 
                continue;
            flipped ^= (1 << toIdx(newRow, newCol));
        }
        
        return flipped;
    }
    
    vector<int> getNext(int cur) {
        vector<int> nexts;
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                nexts.push_back(flip(cur, i, j));
            }
        }
            
        return nexts;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();
        int h = hash(mat);
        unordered_set<int> visited;
        queue<int> q;
        q.push(h);
        int steps = 1;
        
        if(h == 0)
            return 0;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                // try flip all
                auto nexts = getNext(cur);
                for(auto next : nexts) {
                    if(next == 0)
                        return steps;
                    
                    if(visited.count(next))
                        continue;
                    
                    visited.insert(next);
                    q.push(next);
                }
            }
            steps ++;
        }
        
        return -1;
    }
};