class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        // cout << s.substr(start, end-start+1) << endl;
        while(start <= end) {
            if(s[start] != s[end])
                return false;
            start ++;
            end --;
        }
        return true;
    }
    
    void solve(vector<vector<string>>& res, vector<string>& temp, string& s, int idx) {
        if(idx == s.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int i = idx; i < s.size(); i ++) {
            if(isPalindrome(s, idx, i)) {
                string sub = s.substr(idx, i-idx+1);
                // cout << sub << endl;
                temp.push_back(sub);
                solve(res, temp, s, i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        
        solve(res, temp, s, 0);
        
        return res;
    }
};