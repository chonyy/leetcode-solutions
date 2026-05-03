class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> count;

        for (char c : magazine) {
            count[c] ++;
        }

        for (char c : ransomNote) {
            count[c] --;
            if (count[c] < 0) {
                return false;
            }
        }

        return true;
    }
};