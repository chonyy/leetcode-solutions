class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        
        for(char c : s) {
            if(stk.empty() || c != stk.top().first) {
                stk.push({c, 1});
            }
            else {
                stk.top().second ++;
            }
            
            if(!stk.empty() && stk.top().second == k)
                stk.pop();
        }
        
        string res = "";
        while(!stk.empty()) {
            res.append(stk.top().second, stk.top().first);
            stk.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};