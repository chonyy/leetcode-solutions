class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
    unordered_map<string, double> dist;

    string find(string node) {
        if (parent[node] == node) {
            return node;
        }

        // path compression along with dist update
        string oldParent = parent[node];
        string newParent = find(oldParent);
        dist[node] = dist[node] * dist[oldParent];
        parent[node] = newParent;

        return newParent;
    }

    void unionNode(string n1, string n2, double weight) {
        string p1 = find(n1);
        string p2 = find(n2);

        if (p1 == p2) {
            return;
        }

        if (rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] ++;
            dist[p2] = dist[n1] / (dist[n2] * weight);
        }
        else {
            parent[p1] = p2;
            rank[p2] ++;
            dist[p1] = dist[n2] * weight / dist[n1];
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (int i = 0; i < n; i ++) {
            auto& e = equations[i];

            // init if not exist
            string n1 = e[0];
            string n2 = e[1];
            double weight = values[i];

            if (!parent.contains(n1)) {
                parent[n1] = n1;
                rank[n1] = 1;
                dist[n1] = 1;
            }
            if (!parent.contains(n2)) {
                parent[n2] = n2;
                rank[n2] = 1;
                dist[n2] = 1;
            }

            // try union
            unionNode(n1, n2, weight);
        }

        vector<double> res;

        for (auto& q : queries) {
            string n1 = q[0];
            string n2 = q[1];

            if (!parent.contains(n1) || !parent.contains(n2) || find(n1) != find(n2)) {
                res.push_back(-1);
                continue;
            }

            res.push_back(dist[n1] / dist[n2]);
        }

        return res;
    }
};


// a / b = 2
// b / c = 3


// parent[a] = a
// parent[b] = a
// parent[c] = a

// rank[a] = 3
// rank[b] = 1
// rank[c] = 1

// dist[a] = 1
// dist[b] = 1/2
// dist[c] = 1/3 * 1/2 = 1/6


// 1 / (1/6) = 6