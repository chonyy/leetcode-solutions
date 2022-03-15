class Solution {
public:
    double dfs(string& start, string& end, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited) {
        if(start == end) {
            return 1.0;
        }
        
        visited.insert(start);
        
        auto& neighbors = graph[start];
        for(auto& nei : neighbors) {
            if(visited.count(nei.first)) {
                continue;
            }
            
            double val = dfs(nei.first, end, graph, visited); 
            if(val > 0) {
                return nei.second * val; 
            }
        }
        
        visited.erase(start);
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        int n = equations.size();
        
        // create graph
        for(int i= 0; i < n; i ++) {
            string& left = equations[i][0];
            string& right = equations[i][1];
            double val = values[i];
            
            graph[left].push_back({right, val});
            graph[right].push_back({left, 1.0/val});
        }

        vector<double> res;
        for(auto& q : queries) {
            string& start = q[0];
            string& end = q[1];
            
            if(graph.count(start)  == 0 || graph.count(end) == 0) {
                res.push_back(-1.0);
                continue;
            }
            
            unordered_set<string> visited;
            double ans = dfs(start, end, graph, visited);
            res.push_back(ans);
        }
        
        return res;
    }
};