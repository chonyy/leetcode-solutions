class Solution {
public:
    int find(vector<int>& root, int child) {
        if(root[child] == -1)
            return child;
        return root[child] = find(root, root[child]);
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> root(n, -1);
        
        if(edges.size() != n-1) {
            return false;
        }
        
        for(auto e : edges) {
            int px = find(root, e[0]);
            int py = find(root, e[1]);
            
            if(px != py) {
                root[px] = py;
                n --;
            }
        }
        
        return n == 1;
    }
};