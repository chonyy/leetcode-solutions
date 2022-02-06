class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);
        
        for(auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]] ++;
        }
        
        queue<int> q;
        int count = 0;
        
        for(int i = 0; i < numCourses; i ++) {
            if(inDegree[i] == 0) {
                q.push(i);
                count ++;
            }
        }
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            auto& neighbors = graph[cur];
            for(auto nei : neighbors) {
                inDegree[nei] --;
                if(inDegree[nei] == 0) {
                    q.push(nei);
                    count ++;
                }
            }
        }
        
        return count == numCourses;
    }
};