class Solution {
public:
    void dfs(int cur, int parent, unordered_map<int, vector<int>>& graph, unordered_map<char,int>& count, vector<int>& res, string& labels) {
        char lab = labels[cur];
        int oldCount = count[lab];
        count[lab] ++;
        
        auto& neighbors = graph[cur];
        for(auto& nei : neighbors) {
            if(nei == parent) {
                continue;
            }
            dfs(nei, cur, graph, count, res, labels);
        }
        
        res[cur] = count[lab] - oldCount;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> graph;
        
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int> res(n);
        unordered_map<char,int> count;
        dfs(0, -1, graph, count, res, labels);
        
        return res;
    }
};


    //     0:a
    // 1:b     2:c