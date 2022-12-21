class Solution {
public:
    bool coloring(unordered_map<int,vector<int>>& graph, int node, int curColor, vector<int>& color) {
        color[node] = curColor;
        
        auto& neighbors = graph[node];
        for(auto& nei : neighbors) {
            if(color[nei] == curColor) {
                return false;
            }
            if(color[nei] == 0 && coloring(graph, nei, -curColor, color) == false) {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;
        for(auto& e : dislikes) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> color(n+1, 0);
        
        for(int i = 1; i <= n; i ++) {
            if(color[i] != 0) {
                continue;
            }
            if(coloring(graph, i, 1, color) == false) {
                return false;
            }
        }
        
        return true;
    }
};