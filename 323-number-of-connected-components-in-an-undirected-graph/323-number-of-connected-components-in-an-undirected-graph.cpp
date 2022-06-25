class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;
        int size;
    
        UnionFind(int n) {
            rank = vector<int>(n, 0);
            parent = vector<int>(n);
            
            for(int i = 0; i < n; i ++) {
                parent[i] = i;
            }
            
            size = n;
        }
    
        int find(int node) {
            if(parent[node] != node)
                return parent[node] = find(parent[node]);
            return node;
        }
    
        void _union(int x, int y) {
            int px = find(x);
            int py = find(y);
            
            if(px == py)
                return;
            
            if(rank[px] > rank[py]) {
                parent[py] = px;
            }
            else if(rank[px] < rank[py]) {
                parent[px] = py;
            }
            else {
                parent[px] = py;
                rank[px] ++;
                size --;
            }
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf = UnionFind(n);
        
        for(auto& e : edges) {
            uf._union(e[0],e[1]);   
        }
        
        return uf.size;
    }
};