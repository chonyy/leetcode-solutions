class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        unordered_map<string, vector<string>> graph;

        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if(isNeighbor(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        unordered_set<string> visited;
        unordered_map<string, unordered_set<string>> parents;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int step = 1;
        bool found = false;

        while (!q.empty()) {
            int size = q.size();
            step ++;
            unordered_set<string> travelled;

            for (int i = 0; i < size; i ++) {
                string word = q.front();
                q.pop();

                for (auto& nei : graph[word]) {
                    if (visited.contains(nei)) {
                        continue;
                    }
                    parents[nei].insert(word);

                    if (!travelled.contains(nei)) {
                        q.push(nei);
                    }
                    travelled.insert(nei); // can't use visited here. Otherwise it will block subsequent node to build the backtrack path

                    if (nei == endWord) {
                        found = true;
                    }
                }
            }

            for (string word : travelled) {
                visited.insert(word);
            }

            if (found) {
                break;
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        path.push_back(endWord);

        backtrack(endWord, beginWord, parents, path, res);

        return res;
    }

    void backtrack(string& word, string& end, unordered_map<string, unordered_set<string>>& parents, vector<string>& path, vector<vector<string>>& res) {
        if (word == end) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }

        for (auto p : parents[word]) {
            path.push_back(p);
            backtrack(p, end, parents, path, res);
            path.pop_back();
        }
    }

    bool isNeighbor(string& w1, string& w2) {
        int n = w1.size();
        int diff = 0;

        for (int i = 0; i < n; i ++) {
            if(w1[i] != w2[i]) {
                diff ++;
            }
        }
        
        return diff == 1;
    }
};