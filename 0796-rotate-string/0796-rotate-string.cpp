class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        int n = s.size();
        for (int i = 0; i < n; i ++) {
            if (tryMatch(s, i, goal, n)) {
                return true;
            }
        }
        
        return false;
    }

    bool tryMatch(string& s, int start, string& goal, int n) {
        for (int i = 0; i < n; i ++) {
            int sIdx = (start + i) % n;
            if (goal[i] != s[sIdx]) {
                return false;
            }
        }
        
        return true;
    }
};