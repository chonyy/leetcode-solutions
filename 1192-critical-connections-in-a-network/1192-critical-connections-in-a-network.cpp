class Solution {
public:
    int n;
    int dfs(unordered_map<int, vector<int>>& graph, int node, int depth, vector<vector<int>>& res, vector<int>& rank) {
        // visiting
        if(rank[node] >= 0) {
            return rank[node];
        }
        
        // update rank
        rank[node] = depth;
        int minDepth = n;
        auto& neighbors = graph[node];
        
        for(auto& nei : neighbors) {
            // skip parent
            if(rank[nei] == depth-1 || rank[nei] == n) {
                continue;
            }
            int neiDepth = dfs(graph, nei, depth+1, res, rank);
            minDepth = min(minDepth, neiDepth);
            if(neiDepth > depth) {
                res.push_back({node, nei});
            }
        }
        
        rank[node] = n;
        return minDepth;
    }
    
    void createGraph(vector<vector<int>>& connections, unordered_map<int, vector<int>>& graph) {
        for(auto& e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        createGraph(connections, graph);
        vector<vector<int>> res;
        vector<int> rank(n, -2);
        this->n = n;
        
        dfs(graph, 0, 0, res, rank);
        
        return res;
    }
};