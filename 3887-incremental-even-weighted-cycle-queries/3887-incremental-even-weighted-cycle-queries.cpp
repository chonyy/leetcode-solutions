// Component A:        Component B:
//     p1 (root)           p2 (root)
//     |  dist[n1]         |  dist[n2]
//     n1                  n2

// We know: n1 --w-- n2 (the new edge)


// We want to attach p2 under p1. We need dist[p2] = distance from p2 to p1.

// The path from p2 to p1 goes: p2 → n2 → n1 → p1

// p2 →(dist[n2])→ n2 →(w)→ n1 →(dist[n1])→ p1

// dist[p2] = dist[n2] + w + dist[n1]


// That's it! We DO know the distance — it's dist[n1] + dist[n2] + w.

// The key: set dist[p2], not dist[n2]. n2 already has its dist set correctly (relative to its old root p2). We're only moving p2 — it's the one getting a new parent.

class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;
    unordered_map<int,int> dist;

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }

        int oldParent = parent[node];
        int p = find(oldParent);
        dist[node] = dist[node] + dist[oldParent];
        parent[node] = p;

        return p;
    }

    int unionNode(int n1, int n2, int weight) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 != p2) {
            if (rank[p1] >= rank[p2]) {
                parent[p2] = p1;
                rank[p1] ++;
                dist[p2] = dist[n2] + weight + dist[n1];
            }
            else {
                parent[p1] = p2;
                rank[p2] ++;
                dist[p1] = dist[n2] + weight + dist[n1];
            }
            return true;
        }
        else if (p1 == p2 && (dist[n1] + dist[n2] + weight) % 2 == 0) {
            return true;
        }

        return false;
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
            rank[i] = 1;
            dist[i] = 0;
        }

        int res = 0;

        for (auto& e : edges) {
            int n1 = e[0];
            int n2 = e[1];
            int weight = e[2];

            if (unionNode(n1, n2, weight)) {
                res ++;
            }
        }
        

        return res;
    }
};