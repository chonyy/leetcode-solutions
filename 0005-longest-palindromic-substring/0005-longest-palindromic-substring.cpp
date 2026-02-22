class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxLen = 0;

        if (s.size() == 1) {
            return s;
        }

        for (int i = 1; i < n; i ++) {
            tryExpand(s, i-1, i, start, maxLen);
            tryExpand(s, i, i, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

    void tryExpand(string& s, int l, int r, int& start, int& maxLen) {
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r]) {
                break;
            }

            int len = r - l + 1;

            if (len > maxLen) {
                maxLen = len;
                start = l;
            }

            l --;
            r ++;
        }
    }
};

// dp[0][0] = 1
// dp[1][1] = 1

