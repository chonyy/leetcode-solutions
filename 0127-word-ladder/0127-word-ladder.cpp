class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        unordered_map<string, vector<string>> graph;

        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if(isNeighbor(wordList[i], wordList[j])) {
                    // cout << wordList[i] << " " << wordList[j] << endl;
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int step = 1;

        while (!q.empty()) {
            int size = q.size();
            step ++;
            // cout << step << endl;

            for (int i = 0; i < size; i ++) {
                string word = q.front();
                // cout << "word " << word << endl;
                q.pop();

                for (auto& nei : graph[word]) {
                    // cout << "nei " << nei << endl;
                    if (visited.contains(nei)) {
                        continue;
                    }
                    visited.insert(nei);

                    if (nei == endWord) {
                        return step;
                    }

                    // cout << nei << endl;
                    q.push(nei);
                }
            }
        }

        return 0;
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