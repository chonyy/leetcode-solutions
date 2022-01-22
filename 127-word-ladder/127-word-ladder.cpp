class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q;
        
        if(words.find(endWord) == words.end()) 
            return 0;
        
        q.push(beginWord);
        int steps = 1;
        
        while(!q.empty()) {
            int size = q.size();
            // cout << steps << endl;
            for(int i = 0; i < size; i ++) { 
                auto cur = q.front();
                q.pop();
                
                // Try all possible transformation M
                for(int j = 0; j < cur.size(); j ++) {
                    string candidate = cur;
                    for(char c = 'a'; c <= 'z'; c ++) {
                        if(cur[j] == c)
                            continue;
                        
                        candidate[j] = c;
                        if(candidate == endWord) {
                            return steps+1;
                        }
                        
                        if(words.find(candidate) == words.end()) {
                            continue;
                        }
                        
                        // cout << candidate << endl;
                        words.erase(candidate);
                        q.push(candidate);
                    }
                }
            }
            steps ++;
        }
        
        return 0;
    }
};