class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int res = 0;

        for (string& op : operations) {
            if (op[0] == 'C') {
                res -= stk.top();
                stk.pop();
            } else if (op[0] == '+') {
                int first = stk.top();
                stk.pop();
                int second = stk.top();


                stk.push(first);
                stk.push(first + second);
                res += first + second;
            } else if (op[0] == 'D') {
                res += stk.top() * 2;
                stk.push(stk.top() * 2);
            } else {
                // check negation and parse number
                int negative = 1;
                int idx = 0;
                
                if (op[0] == '-') {
                    negative = -1;
                    idx ++;
                }

                int num = 0;
                while (idx < op.size()) {
                    num = num * 10;
                    num += op[idx] - '0';
                    idx ++;
                }
                stk.push(num * negative);
                res += num * negative;
            }
        }

        return res;
    }
};