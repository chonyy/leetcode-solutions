class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = maze[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        
        auto cmp = [](pair<pair<int,int>, int>& p1, pair<pair<int,int>, int>& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, decltype(cmp)> pq(cmp);
        
        distance[start[0]][start[1]]= 0;
        pq.push({{start[0], start[1]}, 0});
        
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int row = cur.first.first;
            int col = cur.first.second;
            int step = cur.second;

            for(auto& dir : dirs) {
                int newRow = row;
                int newCol = col;
                int newStep = step;
                while(maze[newRow][newCol] == 0) {
                    newRow += dir[0];
                    newCol += dir[1];
                    newStep ++;

                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                        break;
                    }
                }
                newRow -= dir[0];
                newCol -= dir[1];
                newStep --;

                if(distance[newRow][newCol] != INT_MAX && newStep >= distance[newRow][newCol]) {
                    continue;
                }
                if(newRow == destination[0] && newCol == destination[1]) {
                    return newStep;
                }

                distance[newRow][newCol] = newStep;
                pq.push({{newRow, newCol}, newStep});
            }
        }
        
        return -1;
    }
};