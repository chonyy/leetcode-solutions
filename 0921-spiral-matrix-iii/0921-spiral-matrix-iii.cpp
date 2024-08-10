class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int nums = rows * cols;
        int dirCount = 4;
        int curDir = 0;
        int dist = 1;
        vector<vector<int>> res;

        res.push_back({rStart, cStart});
        
        while(res.size() < nums) {
            for(int i = 0; i < 2; i ++) {
                for(int d = 0; d < dist; d ++) {
                    auto& dir = dirs[curDir];
                    rStart += dir[0];
                    cStart += dir[1];

                    // cout << rStart << " " << cStart << endl;

                    if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        res.push_back({rStart, cStart});
                    }
                }
                curDir = (curDir + 1) % dirCount;
            }
            dist ++;
        }

        return res;
    }
};