class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int res = 0;
        unordered_set<char> seen;

        while (r < n) {
            char c = s[r];

            while (seen.contains(c)) {
                seen.erase(s[l]);
                l ++;
            }

            seen.insert(c);
            r ++;

            res = max(res, r - l);
        }

        return res;
    }
};