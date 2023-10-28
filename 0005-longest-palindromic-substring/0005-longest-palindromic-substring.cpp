class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        int start = 0;
        string res;
        for(int i = 0; i < n; i ++) {
            int curLen =  max(getPalindromeLen(s, i, i, n), getPalindromeLen(s, i, i+1, n));
            if(curLen > maxLen) {
                maxLen = curLen;
                start = i - (curLen-1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

    int getPalindromeLen(string s, int start, int end, int n) {
        while(start >= 0 && end < n && s[start] == s[end]) {
            start --;
            end ++;
        }
        return end - start - 1;
    }
};