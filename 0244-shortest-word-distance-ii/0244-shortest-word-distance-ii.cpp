class WordDistance {
public:
    unordered_map<string, vector<int>> pos;
    WordDistance(vector<string>& wordsDict) {
        int n = wordsDict.size();

        for (int i = 0; i < n; i ++) {
            string& s = wordsDict[i];
            pos[s].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& pos1 = pos[word1];
        vector<int>& pos2 = pos[word2];

        int res = INT_MAX;

        for (int i : pos1) {
            for (int j : pos2) {
                res = min(res, abs(i - j));
            }
        }

        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */