class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,unordered_set<int>> obs;

        for (auto& ob : obstacles) {
            obs[ob[0]].insert(ob[1]);
        }

        int r = 0;
        int c = 0;
        int curDir = 0;
        int res = 0;

        for (int com : commands) {
            if (com < 0) {
                curDir = turn(com, curDir);
                continue;
            }

            for (int i = 0; i < com; i ++) {
                int newR = r + dirs[curDir][0];
                int newC = c + dirs[curDir][1];

                if (obs.contains(newR) && obs[newR].contains(newC)) {
                    // cout << "hit " << newR << " " << newC << endl;
                    break;
                }

                r = newR;
                c = newC;
                res = max(res, r * r + c * c);
            }
        }
        

        return res;
    }

    int turn(int com, int dir) {
        if (com == -2) {
            dir --;

            if (dir < 0) {
                return 4 + dir;
            }
            return dir;
        }

        return (dir + 1) % 4;
    }
};

// 0 1 2 3
