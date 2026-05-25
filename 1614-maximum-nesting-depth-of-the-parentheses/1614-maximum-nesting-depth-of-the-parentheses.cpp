class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int open = 0;

        for (char c : s) {
            if (c != '(' && c != ')') {
                continue;
            }

            if (c == '(') {
                open ++;
            }
            else {
                open --;
            }
            res = max(res, open);
        }

        return res;
    }
};