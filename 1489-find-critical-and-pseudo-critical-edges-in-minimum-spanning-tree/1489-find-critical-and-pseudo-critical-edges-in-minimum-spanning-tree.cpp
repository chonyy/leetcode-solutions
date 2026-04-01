class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    bool unionNode(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) return false;

        if (rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // append idx to edges
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // sort edges
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        // find minWeight with MST
        int minWeight = getWeight(n, edges);

        // loop through edges, try remove one. If weight > minWeight, it's critical
        // force adding edge, if weight == minWeight, it's pseudo
        vector<int> critical, pseudo;

        for (auto& e : edges) {
            int n1 = e[0], n2 = e[1], testW = e[2], i = e[3];

            // try remove
            UnionFind uf(n);
            int weight = 0;
            for (auto& other : edges) {
                if (other[3] == i) continue;
                if (uf.unionNode(other[0], other[1])) {
                    weight += other[2];
                }
            }

            // Got smaller weight or can't get MST at all
            if (*max_element(uf.rank.begin(), uf.rank.end()) != n || weight > minWeight) {
                critical.push_back(i);
                continue;
            }

            // try force adding
            UnionFind uf2(n);
            uf2.unionNode(n1, n2);
            weight = testW;

            for (auto& other : edges) {
                if (uf2.unionNode(other[0], other[1])) {
                    weight += other[2];
                }
            }

            if (weight == minWeight) {
                pseudo.push_back(i);
            }
        }

        return {critical, pseudo};
    }

    int getWeight(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        int res = 0;

        for (auto& e : edges) {
            if (uf.unionNode(e[0], e[1])) {
                res += e[2];
            }
        }

        return res;
    }
};