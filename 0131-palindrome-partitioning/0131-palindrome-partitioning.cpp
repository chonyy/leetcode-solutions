class Solution {
public:
    unordered_set<string> mem;

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;

        backtrack(res, temp, s, 0);
        
        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& temp, string& s, int idx) {
        if (idx == s.size()) {
            res.push_back(temp);
            return;
        }

        int remainLen = s.size() - idx; 
        for (int i = 1; i <= remainLen; i ++) {
            int end = idx + i - 1;
            
            string sub = s.substr(idx, i);
            if (mem.contains(sub) || isPalindrome(s, idx, end)) {
                mem.insert(sub);
                // cout << sub << endl;
                temp.push_back(sub);
                backtrack(res, temp, s, idx + i);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }

            start ++;
            end --;
        }

        return true;
    }
};