class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;

        if (buildGraph(graph, inDegree, words) == false) {
            return "";
        }

        queue<char> q;
        for (auto& entry : inDegree) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }

        string res = "";

        while (!q.empty()) {
            char cur = q.front();
            q.pop();
            res += cur;

            auto& neighbors = graph[cur];
            for (auto nei : neighbors) {
                inDegree[nei] --;
                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return res.size() == inDegree.size() ? res : "";
    }

    bool buildGraph(unordered_map<char, vector<char>>& graph, unordered_map<char, int>& inDegree, vector<string>& words) {
        int n = words.size();

        for (string& w : words) {
            for (char c : w) {
                inDegree[c] = 0;
            }
        }

        for (int i = 1; i < n; i ++) {
            string& w1 = words[i-1];
            string& w2 = words[i];

            int len = min(w1.size(), w2.size());

            for (int i = 0; i < len; i ++) {
                if (w1[i] != w2[i]) {
                    graph[w1[i]].push_back(w2[i]);
                    inDegree[w2[i]] ++;
                    break;
                }

                if (i == len - 1 && w1.size() > w2.size()) {
                    return false;
                }
            }
        }

        return true;
    }
};