class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // <time, node>
        unordered_map<int, vector<pair<int,int>>> graph;        
        
        for(auto& edge : times) {
            graph[edge[0]].push_back({edge[2], edge[1]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        unordered_set<int> visited;
        pq.push({0, k});
        int ans = 0;
        
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int curTime = cur.first;
            int curNode = cur.second;
            // skip if visited
            if(visited.find(curNode) != visited.end()) {
                continue;
            }
            
            // cout << curNode << " " << curTime << endl;
            // set to visited
            // update ans
            // push all neighbor edges
            visited.insert(curNode);
            ans = max(ans, curTime);
            
            auto& neighbors = graph[curNode];
            for(auto nei : neighbors) {
                // cout << "nei " << nei.second << endl;
                if(visited.find(nei.second) != visited.end()) {
                    continue;
                }
                
                pq.push({nei.first + curTime, nei.second});
            }
        }
        
        return visited.size() == n ? ans : -1;
    }
};