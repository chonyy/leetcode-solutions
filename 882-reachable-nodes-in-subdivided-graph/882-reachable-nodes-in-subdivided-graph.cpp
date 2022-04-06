class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> visited;
        unordered_map<int, unordered_map<int,int>> graph;
        
        // build graph
        for(auto& e : edges) {
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
        }
        
        pq.push({maxMoves, 0});
        // visited[0] = maxMoves;
        
        // start djisktra
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int move = cur.first;
            int node = cur.second;
            cout << node << " " << move << endl;
            
            if(visited.count(node)) {
                continue;
            }
            visited[node] = move;
            
            auto& neighbors = graph[node];
            for(auto nei : neighbors) {
                int newMove = move - nei.second - 1;
                // cout << "nei" << endl;
                // cout << nei.first << " " << newMove << endl;
                
                if(visited.count(nei.first) || newMove < 0) {
                    continue;
                }
                
                pq.push({newMove, nei.first});
                // visited[nei.first] = newMove;
            }
        }
        
        int res = visited.size();
        for(auto& e : edges) {
            int u = visited.count(e[0]) ? visited[e[0]] : 0;
            int v = visited.count(e[1]) ? visited[e[1]] : 0;
            res += min(e[2], u + v);
        }
        
        return res;
    }
};