class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;
        int visited = 0;

        // build graph
        // keep track of inDegree
        if (!buildGraph(graph, inDegree, words))
            return "";

        cout << inDegree.size() << endl;

        // return empty if no inDegree == 0
        queue<char> q;
        string res = "";
        for (auto& entry : inDegree) {
            if (entry.second == 0) {
                q.push(entry.first);
                res.push_back(entry.first);
                visited ++;
            }
        }

        if (q.empty()) {
            return "";
        }

        // Start with nodes with 0 inDegree
        // topological sort
        // add to res string when inDegree == 0
        while (!q.empty()) {
            char cur = q.front();
            q.pop();

            vector<char>& neighbors = graph[cur];
            for (char nei : neighbors) {
                inDegree[nei] --;

                if (inDegree[nei] == 0) {
                    res.push_back(nei);
                    q.push(nei);
                    visited ++;
                }
            }
        }

        return visited == inDegree.size() ? res : "";
    }

    bool buildGraph(unordered_map<char, vector<char>>& graph, unordered_map<char, int>& inDegree, vector<string>& words) {
        int n = words.size();

        for (string& word : words) {
            for (char c : word) {
                inDegree[c] = 0;
            }
        }

        for (int i = 1; i < n; i ++) {
            string& w1 = words[i-1];
            string& w2 = words[i];

            // find the first different
            int len = min(w1.size(), w2.size());

            for (int j = 0; j < len; j ++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    inDegree[w2[j]] ++;
                    break;
                }

                if (j == len-1 && w1.size() > w2.size()) {
                    return false;
                }
            }
        }

        return true;
    }
};


// "hrn",
// "hrf", // r -> f
// "er",  // h -> e
// "enn", // r -> n
// "rfnn" // e -> r