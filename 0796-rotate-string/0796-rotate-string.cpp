class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        vector<int> lps =  buildLps(goal);

        string newS = s + s;

        int n = newS.size();
        int m = goal.size();
        int i = 0;
        int j = 0;

        while (i < n) {
            if (newS[i] == goal[j]) {
                i ++;
                j ++;
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
                return true;
            }
        }
        
        
        return false;
    }

    vector<int> buildLps(string& s) {
        int n = s.size();
        vector<int> lps(n);

        int i = 1;
        int j = 0;

        while (i < n) {
            if (s[i] == s[j]) {
                j ++;
                lps[i] = j;
                i ++;
            }
            else {
                if (j > 0) {
                    j = lps[j-1];
                }
                else {
                    j = 0;
                    i ++;
                }
            }
        }

        return lps;
    }
};