class Solution {
public:
    vector<pair<int,int>> dirs = {{1,2},{2,1},{2,-1},{1,-2},
                                         {-1,-2},{-2,-1},{-2,1},{-1,2}};
    int minKnightMoves(int x, int y) {
        queue<pair<int,int>> startQueue, endQueue;
        unordered_set<int> startVisit, endVisit;

        if (x == 0 && y == 0) {
            return 0;
        }

        startQueue.push({0, 0});
        startVisit.insert(key(0, 0));
        endQueue.push({x, y});
        endVisit.insert(key(x, y));

        int steps = 1;

        while (!startQueue.empty() || !endQueue.empty()) {
            if (endQueue.size() > startQueue.size()) {
                swap(startQueue, endQueue);
                swap(startVisit, endVisit);
            }

            int size = startQueue.size();
            for (int i = 0; i < size; i ++) {
                auto cur = startQueue.front();
                int curX = cur.first;
                int curY = cur.second;
                int curKey = key(curX, curY);
                startQueue.pop();

                for (auto& dir : dirs) {
                    int newX = curX + dir.first;
                    int newY = curY + dir.second;
                    int newKey = key(newX, newY);

                    if (endVisit.contains(newKey)) {
                        return steps;
                    }

                    if (startVisit.contains(newKey)) {
                        continue;
                    }

                    startQueue.push({newX, newY});
                    startVisit.insert(newKey);
                }
            }

            steps ++;
        }

        return -1;
    }

    int key(int x, int y) {
        return x * 1000 + y;
    }
};