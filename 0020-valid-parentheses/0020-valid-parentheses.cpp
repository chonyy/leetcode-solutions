class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                stk.push(c);
            }
            else if(stk.empty()) {
                return false;
            }
            else if(c == ')' && stk.top() != '(') {
                return false;
            }
            else if(c == ']' && stk.top() != '[') {
                return false;
            }
            else if(c == '}' && stk.top() != '{') {
                return false;
            }
            else {
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};