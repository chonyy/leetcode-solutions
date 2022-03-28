class Solution {
public:
    void createGraph(vector<vector<int>>& edges, unordered_map<int,vector<int>>& graph) {
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
    }
    
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        int targetLen = targetPath.size();
        int nodes = n;
        unordered_map<int, vector<int>> graph;
        createGraph(roads, graph);
        
        vector<vector<int>> dp(targetLen, vector<int>(nodes, targetLen));
        vector<vector<int>> path(targetLen, vector<int>(nodes, 0));
        
        // init first edit cost
        for(int node = 0; node < nodes; node ++) {
            dp[0][node] = !(names[node] == targetPath[0]);
        }
        
        // populate dp
        for(int i = 1; i < targetLen; i ++) {
            // cout << i << endl;
            for(int node = 0; node < nodes; node ++) {
                // cout << "node " << node << endl;
                auto& neighbors = graph[node];
                // get smallest cost from the neighbors
                for(auto& nei : neighbors) {
                    if(dp[i-1][nei] < dp[i][node]) {
                        dp[i][node] = dp[i-1][nei];
                        path[i][node] = nei;
                    }
                }
                
                // add cur new cost
                dp[i][node] += !(names[node] == targetPath[i]);
            }
        }
        
        int minCost = targetLen;
        int start = 0;
        for(int node = 0; node < nodes; node ++) {
            int cost = dp[targetLen-1][node];
            if(cost < minCost) {
                minCost = cost;
                start = node;
            }
        }
        
        vector<int> res;
        for(int i = targetLen-1; i >= 0; i --) {
            res.push_back(start);
            int prev = path[i][start];
            start = prev;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};