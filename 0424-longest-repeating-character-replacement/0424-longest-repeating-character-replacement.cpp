class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int l = 0;
        int r = 0;
        int res = 0;
        int maxF = 0;

        while (r < s.size()) {
            count[s[r]] ++;
            maxF = max(maxF, count[s[r]]);

            while (r - l + 1 - maxF > k) {
                count[s[l]] --;
                l ++;
            }

            res = max(res, r - l + 1);
            r ++;
        }

        return res;
    }
};


// A A B A B B A
// l
// r


