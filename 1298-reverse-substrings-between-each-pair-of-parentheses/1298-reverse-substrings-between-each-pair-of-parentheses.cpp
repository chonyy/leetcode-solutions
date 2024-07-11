class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;

        for(char c : s) {
            if(c == ')') {
                queue<char> q;
                while(stk.top() != '(') {
                    q.push(stk.top());
                    stk.pop();
                }
                stk.pop();

                while(!q.empty()) {
                    stk.push(q.front());
                    q.pop();
                }
            }
            else{
                stk.push(c);
            }
        }

        string res = "";
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};