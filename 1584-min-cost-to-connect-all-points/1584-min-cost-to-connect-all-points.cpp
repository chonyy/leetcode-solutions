class UnionFind {
private:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
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
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        UnionFind uf = UnionFind(n);

        vector<vector<int>> edges;

        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                auto& p1 = points[i];
                auto& p2 = points[j];
                int cost = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);

                edges.push_back({cost, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        
        int res = 0;

        for (auto& e : edges) {
            if (uf.unionNode(e[1], e[2])) {
                res += e[0];
            }
        }

        return res;
    }
};