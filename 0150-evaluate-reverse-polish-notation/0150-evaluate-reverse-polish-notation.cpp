class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;

        for(string token : tokens) {
            if(isdigit(token.back())) {
                stk.push(stoi(token));
            }
            else {
                long long op2 = stk.top();
                stk.pop();
                long long op1 = stk.top();
                stk.pop();
                cout << op1 << " " << op2 << " " << token << endl;
                if(token == "+") {
                    stk.push(op1 + op2);
                }
                if(token == "-") {
                    stk.push(op1 - op2);
                }
                if(token == "*") {
                    stk.push(op1 * op2);
                }
                if(token == "/") {
                    stk.push(op1 / op2);
                }
            }
        }

        return stk.top();
    }
};