class UnionFind {
private:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;
public:

    UnionFind(int n) {
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
    }

    bool unionNode(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) {
            return false;
        }

        if (rank[p1] >= rank[p2]) {
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
        // cout << node << endl;
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) {
            return false;
        }

        UnionFind uf = UnionFind(n);

        for (auto& e : edges) {
            if (uf.unionNode(e[0], e[1]) == false) {
                return false;
            }
        }

        return true;
    }
};