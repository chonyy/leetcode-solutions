class UnionFind {
    public:
        vector<int> parent;
        int size = 0;

        UnionFind(int n) {
            parent = vector<int>(n, 0);
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

        void unionn(int a, int b) {
            int pa = find(a);
            int pb = find(b);

            if(pa != pb) {
                parent[pa] = pb;
                size --;
            }
        }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        auto uf = UnionFind(n);
        sort(logs.begin(), logs.end());
        
        for(auto& log : logs) {
            uf.unionn(log[1], log[2]);
            if(uf.size == 1)
                return log[0];
        }
        
        return -1;
    }
};