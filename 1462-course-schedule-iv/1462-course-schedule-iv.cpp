class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, unordered_set<int>> pres;

        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i ++) {
            dfs(graph, i, pres);
        }

        vector<bool> res;

        for (auto& q : queries) {
            res.push_back(pres[q[1]].contains(q[0]));
        }

        return res;
    }

    unordered_set<int>& dfs(unordered_map<int,vector<int>>& graph, int node, unordered_map<int, unordered_set<int>>& pres) {
        if (pres.contains(node)) {
            return pres[node];
        }

        pres[node].insert(node);
        auto& neighbors = graph[node];

        for (int nei : neighbors) {
            unordered_set<int>& neighborPre = dfs(graph, nei, pres);
            pres[node].insert(neighborPre.begin(), neighborPre.end());

        }
        return pres[node];
    }
};