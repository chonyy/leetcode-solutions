class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;

        while (l < r) {
            // pre filter
            // skip non alpha
            while (l < r && !isalnum(s[l])) {
                l ++;
                // cout << l << " " << r << endl;
            }
            while (l < r && !isalnum(s[r])) {
                r --;
                // cout << l << " " << r << endl;
            }

            // transform upper to lower
            if (tolower(s[l]) != tolower(s[r])) {
                // cout << l << " " << r << endl;
                // cout << s[l] << " " << s[r] << endl;
                return false;
            }

            l ++;
            r --;
        }

        return true;
    }
};