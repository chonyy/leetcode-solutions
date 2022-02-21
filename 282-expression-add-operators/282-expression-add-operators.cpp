class Solution {
public:
    void solve(string& num, int idx, string exp, long val, long prev, int target, vector<string>& res) {
        if(idx == num.size()) {
            if(val == target)
                res.push_back(exp);
            return;
        }
        
        // loop through all possibilities
        for(int i = 1; i <= num.size() - idx; i ++) {
            string sub = num.substr(idx, i);
            
            if(sub.size() > 1 && sub[0] == '0')
                continue;
            
            long cur = stol(sub);
            
            // empty first case
            if(exp.size() == 0) {
                solve(num, i, sub, cur, cur, target, res);
            }
            else {
                // add
                solve(num, idx+i, exp + "+" + sub, val+cur, cur, target, res);
                // minus
                solve(num, idx+i, exp + "-" + sub, val-cur, -cur, target, res);
                // multiply
                solve(num, idx+i, exp + "*" + sub, val-prev+prev*cur, prev*cur, target, res);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        solve(num, 0, "", 0, 0, target, res);
        return res;
    }
};