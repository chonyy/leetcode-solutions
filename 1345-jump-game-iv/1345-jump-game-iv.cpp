class Solution {
public:
    int n;
    vector<int> getNeighbors(int idx, unordered_map<int, unordered_set<int>>& group, vector<int>& arr) {
        vector<int> neighbors;
        int val = arr[idx];
        if(idx > 0) {
            neighbors.push_back(idx-1);
        }
        if(idx < n-1) {
            neighbors.push_back(idx+1);
        }
        if(group.count(val)) {
            for(auto& entry : group[val]) {
                neighbors.push_back(entry);
            }
            group.erase(val);
        }
        
        return neighbors;
    }
    
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        this->n = n;
        unordered_map<int, unordered_set<int>> group;
        
        if(n == 1)
            return 0;
        
        for(int i = 0; i < n; i++) {
            group[arr[i]].insert(i);
        }
        
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);
        int steps = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();
                auto neighbors = getNeighbors(cur, group, arr);
                
                for(auto& nei : neighbors) {
                    if(visited.count(nei)) {
                        continue;
                    }
                    if(nei == n-1) {
                        return steps;
                    }
                    // cout << nei << endl;
                    q.push(nei);
                    visited.insert(nei);
                }
            }
            // cout << endl;
            steps ++;
        }
        
        return -1;
    }
};