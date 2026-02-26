class Solution {
public:
    bool checkValidString(string s) {
        // if meet )
        //     try consume (
        //     if not, try consume *

        // for remaining (, try consume all * after it

        stack<int> stk, star; // store index
        int n = s.size();

        for (int i = 0; i < n; i ++) {
            char c = s[i];

            if (c == ')') {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    continue;
                }
                else if (!star.empty()) {
                    star.pop();
                    continue;
                }
                else {
                    return false;
                }
            }

            if (c == '*') {
                star.push(i);
            }

            if (c == '(') {
                stk.push(i);
            }
        }

        while (!stk.empty() && !star.empty()) {
            if (star.top() < stk.top()) {
                return false;
            }

            stk.pop();
            star.pop();
        }

        return stk.empty();
    }
};

// ( * ) )
//       i

// leftMax = 0
// leftMin = 0

// ( * )
//     i

// leftMax = 1
// leftMin = 0

// * (
// leftMax = 1
// leftMin = 1

// ( * * )
//       i

// leftMax = 2
// leftMin = 0

// ( ( * ) 
