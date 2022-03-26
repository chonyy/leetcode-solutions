class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> pos(n, 0.0);
        unordered_map<int, vector<pair<int,double>>> graph;
        int m = edges.size();
        
        for(int i = 0; i < m; i ++) {
            auto& e = edges[i];
            graph[e[0]].push_back({e[1], succProb[i]});
            graph[e[1]].push_back({e[0], succProb[i]});
        }
        
        queue<pair<int,double>> q;
        q.push({start, 1.0});
        
        while(!q.empty()) {
            auto cur = q.front();
            double curPos = cur.second;
            int curNode = cur.first;
            
            q.pop();
            auto& neighbors = graph[curNode];
            for(auto& nei : neighbors) {
                double newPos = curPos * nei.second;
                // skip if not higher possibility
                if(newPos <= pos[nei.first]) {
                    continue;
                }
                
                // add next
                pos[nei.first] = newPos;
                q.push({nei.first, newPos});
            }
        }
        
        return pos[end];
    }
};