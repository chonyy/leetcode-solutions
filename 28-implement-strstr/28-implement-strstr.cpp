class Solution {
public:
    vector<int> buildPrefix(string& str) {
        int l = 0;
        int r = 1;
        int n = str.size();
        vector<int> res(n, 0);
        
        while(r < n) {
            if(str[l] == str[r]) {
                res[r] = l+1;
                r ++;
                l ++;
            }
            else {
                if(l > 0) {
                    l = res[l-1];
                }
                else {
                    r ++;
                }
            }
        }
        
        return res;
    }
    
    int strStr(string haystack, string needle) {
        auto lps = buildPrefix(needle);
        
        int n = haystack.size();
        int m = needle.size();
        
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
        
        if(j == m)
            return i - m;
        return -1;
    }
};

// "ababc"
// 00010