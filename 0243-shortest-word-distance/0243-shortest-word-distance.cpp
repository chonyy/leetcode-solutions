class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int i = 0;
        int j = 0;
        int n = wordsDict.size();
        int res = INT_MAX;

        while (i < n && j < n) {
            while (i < n && wordsDict[i] != word1) {
                i ++;
            }

            while (j < n && wordsDict[j] != word2) {
                j ++;
            }

            if (i != n && j != n) {
                res = min(res, abs(i - j));
            }

            if (i < j) {
                i ++;
            }
            else {
                j ++;
            }
        }

        return res;
    }
};