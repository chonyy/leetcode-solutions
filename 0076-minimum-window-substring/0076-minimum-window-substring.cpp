class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count;

        for (char c : t) {
            count[c] ++;
        }

        int r = 0;
        int l = 0;
        int n = s.size();
        int remain = t.size();
        int resStart = -1;
        int resLen = INT_MAX;

        while (r < n) {
            if (count[s[r]] > 0) {
                remain --;
            }
            count[s[r]] --;

            while (remain == 0) {
                if (count[s[l]] >= 0) {
                    remain ++;
                }
                count[s[l]] ++;

                int len = r - l + 1;
                if (len < resLen) {
                    resLen = len;
                    resStart = l;
                }

                l ++;
            }

            r ++;
        }

        return resStart == -1 ? "" : s.substr(resStart, resLen);
    }
};

// ADOBECODEBANC
//             r
//          l 

// A: 0
// B: 1
// C: 0
// D: 0
// O: 0
// E: 0
// N: -1

// remain = 1