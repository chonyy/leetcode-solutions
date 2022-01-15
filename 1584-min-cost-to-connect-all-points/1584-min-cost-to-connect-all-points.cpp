class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> dist(n);
        unordered_set<int> visited;
        
        for(int i = 0; i < n; i ++) {
            for(int j = i+1; j < n; j ++) {
                auto& p1 = points[i];
                auto& p2 = points[j];
                int distance = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                
                dist[i].push_back({distance, j});
                dist[j].push_back({distance, i});
            }
        }
        
        int res = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        while(visited.size() < n) {
            // get the shortest candidate
            auto shortest = pq.top();
            pq.pop();
            // cout << shortest.first << endl;
            // skip if visited
            if(visited.find(shortest.second) != visited.end()) {
                continue;
            }
            
            // increment the cost
            // put to visited
            res += shortest.first;
            visited.insert(shortest.second);
            
            // put all neighbors of the new node in 
            auto& neighbors = dist[shortest.second];
            // skip if visited
            for(auto nei : neighbors) {
                if(visited.find(nei.second) != visited.end()) {
                    continue;
                }
                pq.push(nei);
            }
            
        }
        return res;
    }
};