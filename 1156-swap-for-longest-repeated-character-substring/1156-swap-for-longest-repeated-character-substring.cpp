class Solution {
public:
    int maxRepOpt1(string s) {
        int n = s.size();
        int res = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int total = count(s.begin(), s.end(), ch);
            int l = 0;
            int gap = 0;

            for (int r = 0; r < n; r++) {
                gap += s[r] != ch;

                if (gap > 1) {
                    gap -= s[l] != ch;
                    l++;
                }

                res = max(res, min(r - l + 1, total));
            }
        }

        return res;
    }
};