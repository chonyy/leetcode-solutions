class UnionFind {
private:
    unordered_map<int,int> parent;
    unordered_map<int, int> rank;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
    }

    bool merge(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) {
            return false;
        }

        if (rank[p1] > p2) {
            parent[p2] = p1;
            rank[p1] ++;
        }
        else {
            parent[p1] = p2;
            rank[p2] ++;
        }

        return true;
    }

    int find(int node) {
        while (parent[node] != node) {
            node = parent[node];
        }

        return node;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind unionFind = UnionFind(edges.size()+1);

        for (auto& edge : edges) {
            if (!unionFind.merge(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};