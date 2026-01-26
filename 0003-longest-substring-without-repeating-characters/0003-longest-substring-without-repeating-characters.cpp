class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int res = 0;
        unordered_set<char> seen;

        while (r < s.size()) {
            while (seen.contains(s[r])) {
                seen.erase(s[l]);
                l ++;
            }

            // cout << l << " " << r << endl;  
            seen.insert(s[r]);
            res = max(res, r - l + 1);
            r ++;
        }

        return res;
    }
};