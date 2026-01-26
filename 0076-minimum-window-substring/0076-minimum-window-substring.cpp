class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char,int> count;

        for (char c : t) {
            count[c] ++;
        }

        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int ansStart = 0;
        int counter = t.size();
        string res;

        while (r < s.size()) {
            // add new
            if (count[s[r]] > 0) {
                counter --;
            }
            count[s[r]] --;

            while (counter == 0) {
                int len = r - l + 1;

                // get answer
                if (len < minLen) {
                    minLen = len;
                    ansStart = l;
                }

                // previously added
                if (count[s[l]] == 0) {
                    counter ++;
                }

                count[s[l]] ++;
                l ++;
            }

            r ++;
        }

        return minLen == INT_MAX ? "" : s.substr(ansStart, minLen);
    }
};