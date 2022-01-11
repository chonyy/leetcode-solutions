class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int prev = 0;
        int num = 0;
        char op = '+';
        int n = s.size();        
        
        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(isdigit(c)) {
                num *= 10;
                num += c - '0';
            }
            if(i == n-1 || (c != ' ' && !isdigit(c))) {
                // cout << prev << " " << op << " " << num << endl;
                if(op == '+') {
                    ans += prev;
                    prev = num;
                }
                else if(op == '-') {
                    ans += prev;
                    prev = -num;
                }
                else if(op == '*') {
                    prev = prev * num;
                }
                else if(op == '/') {
                    prev = prev / num;
                }
                num = 0;
                op = c;
            }
        }
        
        return ans + prev;
    }
};