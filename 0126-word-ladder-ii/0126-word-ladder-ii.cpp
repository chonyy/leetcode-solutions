class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.insert(beginWord);

        // Build pattern map
        unordered_map<string, vector<string>> patternMap;
        for (auto& w : wordSet) {
            for (int i = 0; i < w.size(); i++) {
                string p = w;
                p[i] = '*';
                patternMap[p].push_back(w);
            }
        }

        unordered_set<string> visited;
        unordered_map<string, unordered_set<string>> parents;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> travelled;

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.size(); j++) {
                    string p = word;
                    p[j] = '*';
                    for (auto& nei : patternMap[p]) {
                        if (nei == word || visited.count(nei)) continue;

                        parents[nei].insert(word);
                        if (travelled.insert(nei).second) {
                            q.push(nei);
                        }
                        if (nei == endWord) found = true;
                    }
                }
            }

            // need to be separated to make sure we travel all parents
            for (auto& w : travelled) visited.insert(w);
        }

        vector<vector<string>> res;
        vector<string> path = {endWord};
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
};