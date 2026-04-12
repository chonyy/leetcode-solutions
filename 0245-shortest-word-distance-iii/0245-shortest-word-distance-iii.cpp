class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> indexs;
        int n = wordsDict.size();

        for (int i = 0; i < n; i ++) {
            indexs[wordsDict[i]].push_back(i);
        }

        int res = INT_MAX;
        // check gap
        if (word1 == word2) {
            auto& pos = indexs[word1];
            for (int i = 1; i < pos.size(); i ++) {
                res = min(res, pos[i] - pos[i-1]);
            }
            return res;
        }

        auto& pos1 = indexs[word1];
        auto& pos2 = indexs[word2];

        int i = 0;
        int j = 0;

        while (i < pos1.size() && j < pos2.size()) {
            res = min(res, abs(pos1[i] - pos2[j]));
            if (pos1[i] < pos2[j]) {
                i ++;
            }
            else {
                j ++;
            }
        }

        return res;
    }
};