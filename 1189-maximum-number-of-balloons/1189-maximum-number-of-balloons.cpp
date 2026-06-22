class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> count;

        for (char c : text) {
            count[c] ++;
        }

        int res = INT_MAX;
        unordered_map<char,int> need;
        string balloon = "balloon";
        for (char c : balloon) {
            need[c] ++;
        }

        for (auto& entry : need) {
            int textCount = count[entry.first];
            int words = textCount / entry.second;
            res = min(res, words);
        }

        return res == INT_MAX ? 0: res;
    }
};