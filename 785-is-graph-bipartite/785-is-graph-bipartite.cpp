class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        queue<int> q;
        
        for(int i = 0; i < n; i ++) {
            if(visited[i])
                continue;
            
            q.push(i);
            // 1: red, 2: blue
            visited[i] = 1;

            while(!q.empty()) {
                int curNode = q.front();
                q.pop();
                int colorToPaint = visited[curNode] == 1 ? 2 : 1;
                auto &neighbors = graph[curNode];
                for(int nei : neighbors) {
                    if(visited[nei] == 0) {
                        visited[nei] = colorToPaint;
                        q.push(nei);
                    }
                    else if(visited[nei] != colorToPaint){
                        return false;
                    }
                }

            }
        }
            
        return true;
    }
};