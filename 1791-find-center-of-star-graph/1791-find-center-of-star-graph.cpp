class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        int n = edges.size();
        
        for(auto& edge : edges) {
            m[edge[0]] ++;
            m[edge[1]] ++;
        }
        
        for(auto& entry : m) {
            if(entry.second == n) {
                return entry.first;
            }
        }
        
        return -1;
    }
};