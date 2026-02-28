class DetectSquares {
public:
    vector<vector<int>> points;
    unordered_map<int, unordered_map<int,int>> countt;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        countt[point[0]][point[1]] ++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int res = 0;

        for (auto& p : points) {
            if (p[0] == x || p[1] == y) {
                continue;
            }

            if (abs(p[0] - x) != abs(p[1] - y)) {
                continue;
            }

            res += countt[x][p[1]] * countt[p[0]][y];
        }

        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

//  3, 10 
//  11, 2
//  3, 2


// 11, 10

