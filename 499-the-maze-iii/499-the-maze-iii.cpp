class Entry {
    public:
        int row;
        int col;
        int steps;
        string path;
        Entry(int row, int col, int steps, string path) {
            this->row = row;
            this->col = col;
            this->steps = steps;
            this->path = path;
        }
};

class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<char> dirChar = {'u', 'r', 'd', 'l'};
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = maze[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        set<string> res;
        int shortest = INT_MAX;
        
        auto cmp = [](Entry& e1, Entry& e2) {
            return e1.steps > e2.steps;
        };
        priority_queue<Entry, vector<Entry>, decltype(cmp)> pq(cmp);
        
        distance[start[0]][start[1]]= 0;
        pq.push(Entry(start[0], start[1], 0, ""));
        
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int row = cur.row;
            int col = cur.col;
            int step = cur.steps;
            // cout << row << " " << col << endl;

            for(int i = 0; i < 4; i ++) {
                auto& dir = dirs[i];
                int newRow = row;
                int newCol = col;
                int newStep = step;
                string newPath = cur.path + dirChar[i];
                while(maze[newRow][newCol] == 0) {
                    newRow += dir[0];
                    newCol += dir[1];
                    newStep ++;

                    if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                        break;
                    }
                    if(newRow == destination[0] && newCol == destination[1]) {
                        if(newStep > shortest) {
                            return *res.begin();
                        }
                        else {
                            shortest = newStep;
                        }
                        res.insert(newPath);
                    }
                }
                newRow -= dir[0];
                newCol -= dir[1];
                newStep --;

                if(newRow == row && newCol == col) {
                    continue;
                }
                
                if(distance[newRow][newCol] != INT_MAX && newStep > distance[newRow][newCol]) {
                    continue;
                }

                distance[newRow][newCol] = newStep;
                pq.push(Entry(newRow, newCol, newStep, newPath));
            }
        }
        
        return res.size() == 0 ? "impossible" : *res.begin();
    }
};

// [0,0,1,0,0]
// [0,0,0,0,0]
// [0,0,0,1,0]
// [1,1,0,1,1]
// [0,0,0,0,0]]
// [0,4]
// [4,4]


// [0,1,0,0,1,0,0,1,0,0]
// [0,0,1,0,0,1,0,0,1,0]
// [0,0,0,0,X,0,1,0,0,1]
// [0,0,0,0,0,0,1,0,0,1]
// [0,1,0,0,1,0,0,1,0,0]
// [0,0,1,0,0,1,0,0,0,0]
// [0,0,0,0,0,0,1,0,0,0]
// [1,0,0,1,0,0,X,0,0,1]
// [0,1,0,0,1,0,0,1,0,0]
// [0,0,0,0,0,1,0,0,1,0]
// [2,4]
// [7,6]