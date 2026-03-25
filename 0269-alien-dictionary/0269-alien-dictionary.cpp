class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;
        unordered_set<char> visiting;
        unordered_set<char> visited;

        // build graph
        // keep track of inDegree
        if (!buildGraph(graph, inDegree, words))
            return "";

        string res = "";

        for (auto& entry : inDegree) {
            char cur = entry.first;
            // cout << "loop " << cur << endl;

            if (hasCycle(graph, visiting, visited, res, cur)) {
                return "";
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool hasCycle(unordered_map<char, vector<char>>& graph, unordered_set<char>& visiting, unordered_set<char>& visited, string& res, char cur) {
        // skip if already visiting -> cycle
        // cout << cur << endl;
        if (visiting.contains(cur)) {
            // cout << "cycle" << endl;
            return true;
        }

        if (visited.contains(cur)) {
                return false;
            }

        visiting.insert(cur);
        vector<char> neighbors = graph[cur];
        for (char nei : neighbors) {
            if (hasCycle(graph, visiting, visited, res, nei)) {
                return true;
            }
        }

        // cout << "finish " << cur << endl;
        res.push_back(cur);
        visited.insert(cur);
        visiting.erase(cur);

        return false;
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