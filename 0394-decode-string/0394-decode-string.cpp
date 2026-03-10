class Solution {
public:
    string decodeString(string s) {
        stack<int> numStk;
        stack<string> stringStk;

        int idx = 0;
        string cur = "";
        int num = 0;

        while (idx < s.size()) {
            // if [, push num to num stack, push cur to stringStk.

            // if ], cur = stringStk.top() + cur * numStk.top()

            // else if digit, accumulate num

            // else cur += c

            char c = s[idx];

            if (c == '[') {
                numStk.push(num);
                stringStk.push(cur);
                num = 0;
                cur = "";
            } else if (c == ']') {
                int oldNum = numStk.top();
                numStk.pop();
                string oldString = stringStk.top();
                stringStk.pop();

                cur = oldString + repeat(cur, oldNum);
                num = 0;
            } else if (isdigit(c)) {
                num = num * 10;
                num += c - '0';
            } else {
                cur += c;
            }

            idx ++;
        }

        return cur;       
    }

    string repeat(string& s, int times) {
        string res;

        for (int i = 0; i < times; i ++) {
            res += s;
        }

        return res;
    }
};

// numStack: 3

// stringStack:

// 3[a]2[bc]
//    i

//  when see [, push num to num stack


//  3[a2[c]]
//         i

// numStack: 3,

// stringStack: a, cc