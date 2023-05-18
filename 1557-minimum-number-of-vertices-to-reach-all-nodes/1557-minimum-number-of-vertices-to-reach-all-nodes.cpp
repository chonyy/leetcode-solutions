class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n, false);
        
        for(auto& e : edges) {
            seen[e[1]] = true;
        }
        
        vector<int> res;
        
        for(int i = 0; i < n; i ++) {
            if(seen[i] == false) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};