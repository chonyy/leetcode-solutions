class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(n+1, 0);
        
        for(auto& e : relations) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            inDegree[e[1]] ++;
        } 
        
        queue<int> q;
        for(int i = 1; i <= n; i ++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int steps = 0;
        int visited = 0;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                visited ++;
                
                auto& neighbors = graph[cur];
                for(auto nei : neighbors) {
                    inDegree[nei] --;
                    if(inDegree[nei] == 0) {
                        q.push(nei);
                    }
                }
            }
            steps ++;
        }
        
        return visited == n ? steps : -1;
    }
};