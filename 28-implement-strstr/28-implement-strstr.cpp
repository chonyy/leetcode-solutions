class Solution {
public:
    vector<int> buildPrefix(string s) {
        int n = s.size();
        int l = 0, r = 1;
        vector<int> prefix(n, 0);
        
        while(r < n) {
            if(s[l] == s[r]) {
                prefix[r] = l+1;
                l ++;
                r ++;
            }
            else {
                if(l > 0) {
                    l = prefix[l-1];
                }
                else {
                    r ++;
                }
            }
        }
        
        return prefix;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if(m == 0) {
            return 0;
        }
        
        if(n == 0) {
            return -1;
        }
        
        auto lps = buildPrefix(needle);
        
        int i = 0;
        int j = 0;
        
        while(i < n && j < m) {
            if(haystack[i] == needle[j]) {
                i ++;
                j ++;
            }
            else {
                if(j > 0) {
                    j = lps[j-1];
                }
                else {
                    i ++;
                }
            }
        }
        
        return j == m ? i - j : -1;
    }
};