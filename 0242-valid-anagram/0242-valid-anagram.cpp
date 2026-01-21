class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;

        if (s.size() != t.size()) {
            return false;
        }

        for (char c : s) {
            count[c] ++;
        }

        for (char c : t) {
            count[c] --;

            if (count[c] < 0) {
                return false;
            }
        }

        return true;
    }
};