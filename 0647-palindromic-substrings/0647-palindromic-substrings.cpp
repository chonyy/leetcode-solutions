class Solution {
public:
    int n;
    int countSubstrings(string s) {
        n = s.size();
        int res = 0;

        for(int i = 0; i < n ; i ++) {
            res += count(s, i, i);
            res += count(s, i, i+1);
        }

        return res;
    }

    int count(string s, int start, int end) {
        int res = 0;

        while(start >= 0 && end < n) {
            if(s[start] != s[end])
                break;

            res ++;

            start --;
            end ++;
        }

        return res;
    }
};