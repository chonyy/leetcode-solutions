class Solution {
public:
    vector<int> res;
    vector<int> count;
    vector<int> dist;
    int n;
    
    void getCountDist(int cur, int prev, unordered_map<int,vector<int>>& graph) {
        auto& neighbors = graph[cur];
        for(int nei : neighbors) {
            if(nei == prev)
                continue;
            
            getCountDist(nei, cur, graph);
            count[cur] += count[nei];
            dist[cur] += dist[nei] + count[nei];
        }
    }
    
    void getRes(int cur, int prev, unordered_map<int,vector<int>>& graph) {
        auto& neighbors = graph[cur];
        for(int nei : neighbors) {
            if(nei == prev) {
                continue;
            }
            dist[nei] =  dist[cur] - count[nei] + (n - count[nei]);
            getRes(nei, cur, graph);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        res = vector<int>(n, 0);
        count = vector<int>(n, 1);
        dist = vector<int>(n, 0);
        
        unordered_map<int, vector<int>> graph;
        
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        getCountDist(0, -1, graph);
        
        // for(int i = 0; i < n; i ++) {
        //     cout << i << endl;
        //     cout << count[i] << " " << dist[i] << endl;
        // }
        
        getRes(0, -1, graph);
        
        return dist;
    }
};