class UnionFind {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    bool contains(int node) { return parent.count(node); }

    void add(int node) {
        parent[node] = node;
        rank[node] = 0;
    }

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    bool unionNode(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) return false;

        if (rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            if (rank[p1] == rank[p2]) rank[p1]++;
        } else {
            parent[p1] = p2;
        }

        return true;
    }
};


class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        UnionFind uf;
        int count = 0;
        vector<int> res;

        for (auto& pos : positions) {
            int idx = pos[0] * n + pos[1];

            if (uf.contains(idx)) {
                res.push_back(count);
                continue;
            }

            uf.add(idx);
            count++;

            for (auto& dir : dirs) {
                int nr = pos[0] + dir[0];
                int nc = pos[1] + dir[1];
                int nIdx = nr * n + nc;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (!uf.contains(nIdx)) continue;

                if (uf.unionNode(idx, nIdx)) count--;
            }

            res.push_back(count);
        }

        return res;
    }
};