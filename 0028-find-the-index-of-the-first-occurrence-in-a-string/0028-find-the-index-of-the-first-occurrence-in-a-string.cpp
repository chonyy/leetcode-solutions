class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps = buildLps(needle);

        int n = haystack.size();
        int m = needle.size();

        int i = 0;
        int j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                j ++;
                i ++;
            }
            else {
                if (j > 0) {
                    j = lps[j-1];
                }
                else {
                    i ++;
                }
            }

            if (j == m) {
                return i - m;
            }
        }

        return -1;
    }

    vector<int> buildLps(string& needle) {
        int n = needle.size();
        vector<int> lps(n);
        
        int i = 1;
        int j = 0;

        while (i < n) {
            if (needle[i] == needle[j]) {
                j ++;
                lps[i] = j;
                i ++;
            }
            else {
                if (j > 0) {
                    j = lps[j-1];
                }
                else {
                    lps[i] = 0;
                    i ++;
                }
            }
        }

        return lps;
    }
};