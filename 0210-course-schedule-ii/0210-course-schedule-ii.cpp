class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create adjacency graphs
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        vector<int> res;

        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]] ++;
        }

        // get starting points with inDegree = 0
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }

        // if no inDegree 0, return false
        if (q.empty()) {
            return {};
        }

        // bfs with queue
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int nei : graph[node]) {
                inDegree[nei] --;

                if (inDegree[nei] == 0) {
                    q.push(nei);
                    res.push_back(nei);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};