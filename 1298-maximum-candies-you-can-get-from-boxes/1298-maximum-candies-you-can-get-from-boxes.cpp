class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // bfs
        queue<int> q;
        unordered_set<int> closedBoxes;
        unordered_set<int> spareKeys;
        int res = 0;

        for (int box : initialBoxes) {
            // if close: add to closedBoxes
            // if open: add to q
            if (status[box] == 1) { // open
                q.push(box);
            }
            else {
                closedBoxes.insert(box);
            }
        }
        
        // when find new key
        //   if existing box: add to queue, remove box from set
        //   if not existing: add to key set
        // when find closed boxes
        //   if existing key: add to queue, remove key from set
        //   if not existing: add to box set
        // when find opened boxes, add to queue
        // sum the candies
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            res += candies[cur];

            // check keys
            for (int k : keys[cur]) {
                // try match with box
                if (closedBoxes.contains(k)) {
                    q.push(k);
                    closedBoxes.erase(k);
                }
                else {
                    spareKeys.insert(k);
                }
            }

            // check boxes
            for (int b : containedBoxes[cur]) {
                if (status[b] == 1) { // open
                    q.push(b);
                }
                else { // try match with key
                    if (spareKeys.contains(b)) {
                        q.push(b);
                        spareKeys.erase(b);
                    }
                    else {
                        closedBoxes.insert(b);
                    }
                }
            }
        }

        return res;
    }
};