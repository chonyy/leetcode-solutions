class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create adjacency graphs
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;

        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]] ++;
        }

        // get starting points with inDegree = 0
        int courses = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (inDegree[i] == 0) {
                q.push(i);
                courses ++;
            }
        }

        // if no inDegree 0, return false
        if (q.empty()) {
            return false;
        }

        // bfs with queue
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int nei : graph[node]) {
                inDegree[nei] --;

                if (inDegree[nei] == 0) {
                    q.push(nei);
                    courses ++;
                }
            }
        }

        return courses == numCourses;
    }
};