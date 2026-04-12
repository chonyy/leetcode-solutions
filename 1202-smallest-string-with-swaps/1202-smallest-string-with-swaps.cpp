class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
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

        int r1 = rank[p1];
        int r2 = rank[p2];

        if (r1 <= r2) {
            parent[p1] = p2;
            rank[p2] ++;
        }
        else {
            parent[p2] = p1;
            rank[p1] ++;
        }

        return true;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionFind uf = UnionFind(n);

        for (auto& p : pairs) {
            uf.unionNode(p[0], p[1]);
        }

        unordered_map<int, string> parentToNode;
        for (int i = 0; i < s.size(); i ++) {
            parentToNode[uf.find(i)].push_back(s[i]);
        }

        for (auto& entry : parentToNode) {
            sort(entry.second.rbegin(), entry.second.rend());
        }

        string res = "";

        for (int i = 0; i < s.size(); i ++) {
            int p = uf.find(i);
            string& cand = parentToNode[p];
            res.push_back(cand.back());
            cand.pop_back();
        }

        return res;
    }
};