class Solution {
    int i;
public:
    int calculate(string s) {
        i = 0;
        return eval(s);
    }

    int eval(string& s) {
        stack<int> stk;
        int num = 0;
        char sign = '+';
        int n = s.size();

        while (i < n) {
            char c = s[i];

            if (isdigit(c)) {
                num = c - '0';
                while (i + 1 < n && isdigit(s[i + 1])) {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
            }

            if (c == '(') {
                i++;              // skip '('
                num = eval(s);    // recurse, i now points at ')'
            }

            if (i == n - 1 || (c != ' ' && !isdigit(c) && c != '(')) {
                if (sign == '+') stk.push(num);
                if (sign == '-') stk.push(-num);
                if (sign == '*') { int t = stk.top(); stk.pop(); stk.push(t * num); }
                if (sign == '/') { int t = stk.top(); stk.pop(); stk.push(t / num); }
                sign = c;
                num = 0;
            }

            if (c == ')') break;  // return to caller, i stays at ')'

            i ++;
        }

        int res = 0;
        while (!stk.empty()) { res += stk.top(); stk.pop(); }
        return res;
    }
};