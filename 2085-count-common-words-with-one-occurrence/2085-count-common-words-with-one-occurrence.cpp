class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;

        for (string & w : words1) {
            m1[w] ++;
        }
        for (string & w : words2) {
            m2[w] ++;
        }

        int res = 0;
        for (auto& entry : m1) {
            if (entry.second == 1) {
                res += m2[entry.first] == 1;
            }
        }

        return res;
    }
};