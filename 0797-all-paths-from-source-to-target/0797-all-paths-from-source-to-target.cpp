class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& path, vector<vector<int>>& graph, int cur) {
        if(cur == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        
        auto& neighbors = graph[cur];
        for(auto nei : neighbors) {
            path.push_back(nei);
            backtrack(res, path, graph, nei);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path = {0};
        
        backtrack(res, path, graph, 0);
        
        return res;
    }
};