class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> busRoute;
        
        for(int i = 0; i < routes.size(); i ++) {
            auto& r = routes[i];
            for(int b : r) {
                busRoute[b].push_back(i);
            }
        }
        
        if(source == target) {
            return 0;
        }
        
        queue<int> q;
        unordered_set<int> visited;
        q.push(source);
        visited.insert(source);
        int steps = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                
                auto& routeNums = busRoute[cur];
                for(auto rn : routeNums) {
                    auto& route = routes[rn]; 
                    for(int b : route) {
                        if(b == target) {
                            return steps;
                        }
                        if(visited.count(b)) {
                            continue;
                        }
                        q.push(b);
                        visited.insert(b);
                    }
                    route.clear();
                }
            }
            steps ++;
        }
        
        return -1;
    }
};