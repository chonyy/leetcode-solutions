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
        
        auto cmp = [](pair<int,double>& p1, pair<int,double>& p2) {
            return p1.second < p2.second;
        };
        priority_queue<pair<int,double>, vector<pair<int,double>>, decltype(cmp)> pq(cmp); 
        pq.push({start, 1.0});
        
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            double curPos = cur.second;
            int curNode = cur.first;
            
            if(curNode == end) {
                return curPos;
            }
            
            auto& neighbors = graph[curNode];
            for(auto& nei : neighbors) {
                double newPos = curPos * nei.second;
                // skip if not higher possibility
                if(newPos <= pos[nei.first]) {
                    continue;
                }
                
                // add next
                pos[nei.first] = newPos;
                pq.push({nei.first, newPos});
            }
        }
        
        return pos[end];
    }
};