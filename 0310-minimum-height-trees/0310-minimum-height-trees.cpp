class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> inDegree;
        unordered_map<int, vector<int>> graph;

        if (edges.size() == 0) {
            return {0};
        }

        for (auto& e : edges) {
            inDegree[e[0]] ++;
            inDegree[e[1]] ++;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;

        for (auto& entry :inDegree) {
            if (entry.second == 1) {
                q.push(entry.first);
            }
        }


        while (n > 2) { // we can only have one node (odd max len), two node (even max len) left 
            int size = q.size();
            n -= size;

            for (int i = 0; i < size; i ++) {
                int cur = q.front();
                q.pop();

                for (int nei : graph[cur]) {
                    inDegree[nei] --;
                    if (inDegree[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> res;

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};

// Tree:   0 - 1 - 2 - 4 - 6
//             |
//             3 - 5