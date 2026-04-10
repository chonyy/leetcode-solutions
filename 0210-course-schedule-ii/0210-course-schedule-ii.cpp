class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;

        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            inDegree[p[0]] ++;
        }

        vector<int> res;
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);

            auto& neighbors = graph[cur];
            for (int nei : neighbors) {
                inDegree[nei] --;
                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};