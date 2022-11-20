class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int n = s.size();
        int sign = 1;
        int res = 0;
        
        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(isdigit(c)) {
                int num = c - '0';
                while(isdigit(s[i+1])) {
                    num = num * 10 + (s[i+1] - '0');
                    i ++;
                }
                res += num * sign;
            }
            if(c == '+') {
                sign = 1;
            }
            if(c == '-') {
                sign = -1;
            }
            if(c == '(') {
                // push original num and sign on stack
                // reinit
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            }
            if(c == ')') {
                // pop sign
                // pop old res
                int sign = stk.top();
                stk.pop();
                int oldRes = stk.top();
                stk.pop();
                
                res = oldRes + sign * res;
            }
        }
        
        return res;
    }
};