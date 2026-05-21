class Solution {
public:
    string minWindow(string s, string t) {
        // count t in map
        // count remain
        int remain = 0;
        unordered_map<char,int> count;

        for (char c : t) {
            remain ++;
            count[c] ++;
        }

        int l = 0;
        int r = 0;
        int n = s.size();
        int ansStart = -1;
        int ansLen = INT_MAX;
        
        // sliding window, moving r
        while (r < n) {
            // cout << "r " << s[r] << endl;

            // if map[r] > 0, remain --, map[r] --
            if (count[s[r]] > 0) {
                remain --;
            }
            count[s[r]] --;

            // while remain == 0
            // - record ans
            // - if map[l] >= 0, remain ++
            // - map[l] ++
            while (remain == 0) {
                // cout << "Move left " << s[l] << endl;
                int curLen = r - l + 1;
                if (curLen < ansLen) {
                    ansLen = curLen;
                    ansStart = l;
                }

                if (count[s[l]] >= 0) {
                    remain ++;
                }
                count[s[l]] ++;
                l ++;
            }

            // cout << remain << endl;
            // cout << endl;
            r ++;
        }

        return ansStart == -1 ? "" : s.substr(ansStart, ansLen);
    }
};