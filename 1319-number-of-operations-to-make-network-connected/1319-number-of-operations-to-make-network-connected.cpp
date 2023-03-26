class Solution {
public:
    void dfs(vector<bool>& seen, vector<vector<int>>& graph, int cur) {
        if(seen[cur] == true) 
            return;
        
        seen[cur] = true;
        auto& neighbors = graph[cur];
        for(auto nei : neighbors) {
            dfs(seen, graph, nei);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int conCount = connections.size();
        if(conCount < n-1) 
            return -1;
        
        vector<vector<int>> graph(n);
        for(auto conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        vector<bool> seen(n, false);
        int connected = 0;
        for(int i = 0; i < n; i ++) {
            if(seen[i] == false) {
                connected ++;
                dfs(seen, graph, i);
            }            
        }
        
        return connected - 1;
    }
};