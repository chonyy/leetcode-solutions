class Solution {
public:
    unordered_map<int, vector<int>> dirs;

    int slidingPuzzle(vector<vector<int>>& board) {
        dirs[0] = {1, 3};
        dirs[1] = {0, 2, 4};
        dirs[2] = {1, 5};
        dirs[3] = {0, 4};
        dirs[4] = {1, 3, 5};
        dirs[5] = {2, 4};

        string end = "123450";
        string start = getState(board);

        if (start == end) {
            return 0;
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int step = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i ++) {
                string cur = q.front();
                q.pop();

                vector<string> neighbors = getNeighbors(cur);

                for (auto& nei : neighbors) {
                    if (visited.contains(nei)) {
                        continue;
                    }
                    visited.insert(nei);

                    cout << nei << endl;

                    if (nei == end) {
                        return step;
                    }

                    q.push(nei);
                }
            }

            step ++;
        }
        
        return -1;
    }

    vector<string> getNeighbors(string& state) {
        int zeroIdx;
        for (int i = 0; i < 6; i ++) {
            if (state[i] == '0') {
                zeroIdx = i;
                break;
            }
        }

        vector<string> neighbors;

        for (int swapIdx : dirs[zeroIdx]) {
            string temp = state;
            swap(temp[swapIdx], temp[zeroIdx]);
            neighbors.push_back(temp);
        }

        return neighbors;
    }

    string getState(vector<vector<int>>& board) {
        string res = "";

        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 3; j ++) {
                res += to_string(board[i][j]);
            }
        }

        return res;
    }
};

// 0 1 2
// 3 4 5


// 0: 1, 3
// 1: 0, 2, 3
// 2: 1, 5
// 3: 0, 4
// 4, 1, 3, 5
// 5, 2, 4