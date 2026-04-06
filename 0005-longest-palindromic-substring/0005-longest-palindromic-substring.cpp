class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 1;
        int startIdx = 0;

        for (int i = 0; i < n; i ++) {
            int newLen = max(tryExpand(s, i, i), tryExpand(s, i, i+1));

            if (newLen > maxLen) {
                maxLen = newLen;
                startIdx = i - (maxLen - 1) / 2;
            }
        }

        return s.substr(startIdx, maxLen);
    }

    int tryExpand(string& s, int l, int r) {
        int len = 0;
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r]) {
                break;
            }

            len = r - l + 1;

            l --;
            r ++;
        }

        return len;
    }
};

// b a a b
//   i