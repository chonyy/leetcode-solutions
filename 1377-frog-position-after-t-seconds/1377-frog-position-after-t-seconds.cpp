class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(n+1);
        vector<int> seen(n+1, 0);
        vector<double> p(n+1);
        queue<int> q;
        
        // Create the graph
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Starting at vertex 1
        p[1] = 1.0;
        q.push(1);
        seen[1] = 1;
        
        // Perform BFS
        for(int i = 0; i < t; i++) {
            int size = q.size();
            
            for(int j = 0; j < size; j++) {
                int cur = q.front();
                q.pop();
                auto& neighbors = graph[cur]; 
                // Calculate the valid childfren by checking the unseen
                int children = 0;
                for(int nei : neighbors) {
                    if(!seen[nei]) {
                        children ++;
                    }
                }                
                
                // Calculate the possibility of traveling to the child
                for(int nei : neighbors) {
                    if(!seen[nei]) {
                        seen[nei] ++;
                        q.push(nei);
                        p[nei] = p[cur] / children;
                        // cout << nei << " " << p[nei] << endl;
                    }
                }
                
                if(children)
                    p[cur] = 0.0;
            }
        }
        
        return p[target];
    }
};