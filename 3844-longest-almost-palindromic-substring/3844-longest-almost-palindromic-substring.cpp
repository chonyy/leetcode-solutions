class Solution {
public:
    
    int almostPalindromic(string s) {
        int n = s.size();
        int res = 0;

        for (int i = 1; i < n; i ++) {
            res = max(res, tryExpand(s, i, i, true));
            res = max(res, tryExpand(s, i-1, i, true));
        }
        
        return res;
    }

    int tryExpand(string& s, int l, int r, bool allow) {
        if (l < 0 && r >= s.size()) {
            return 0;
        }

        if (l < 0 || r >= s.size()) {
            return allow;
        }

        // cout << s[l] << " " << s[r] << endl;

        if (s[l] != s[r]) {
            // cout << "not same" << endl;
            if (!allow) {
                // cout << "end" << endl;
                return 0;
            }
            
            int tempMax = 0;
            tempMax = max(tempMax, tryExpand(s, l-1, r, false));
            tempMax = max(tempMax, tryExpand(s, l, r+1, false));
            return tempMax + 1;
        }

        int matchCount = l == r ? 1 : 2;

        return matchCount + tryExpand(s, l-1, r+1, allow);
    }
};