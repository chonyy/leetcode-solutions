class Solution {
public:
    void remove(string& s, int l, int r, vector<string>& res, int idx) {
        if(l == 0 && r == 0) {
            // cout << s << endl;
            if(isValid(s)) {
                res.push_back(s);
            }
            return;
        }
        
        int n = s.size();
        for(int i = idx; i < n; i ++) {
            if(i > idx && s[i] == s[i-1])
                continue;
            
            char c = s[i];
            string sub = s.substr(0, i) + s.substr(i+1);
            if(c == '(' && l > 0) {
                remove(sub, l-1, r, res, i);
            }
            if(c == ')' && r > 0) {
                remove(sub, l, r-1, res, i);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int r = 0;
        int remainLeft = 0;
        
        for(char c : s) {
            if(c == '(') {
                remainLeft ++;
            }
            if(c == ')') {
                if(remainLeft == 0)
                    r ++;
                else
                    remainLeft --;
            }
        }
        
        l = remainLeft;
        // cout << l << " " << r << endl;
        
        vector<string> res;
        remove(s, l, r, res, 0);
        return res;
        
    }
    
    
    bool isValid(string& s) {
        int leftCount = 0;
        
        for(char c : s) {
            if(c == '(') {
                leftCount ++;
            }
            if(c == ')') {
                leftCount --;
                if(leftCount < 0)
                    return false;
            }
        }
        
        return leftCount == 0;
    }
};

