class Solution {
public:
    string processStr(string s) {
        string res = "";
        
        for (char c : s) {
            if (c == '*') {
                if (res.empty()) {
                    continue;
                }
                res.pop_back();
            }
            else if (c == '#') {
                res.insert(res.end(), res.begin(), res.end());
            }
            else if(c == '%') {
                reverse(res.begin(), res.end());
            }
            else {
                res.push_back(c);
            }
        }

        return res;
    }
};