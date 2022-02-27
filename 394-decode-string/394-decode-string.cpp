class Solution {
public:
    string repeat(string& cur, int times) {
        string res = "";
        
        for(int i = 0; i < times; i ++) {
            res += cur;
        }
        
        return res;
    }
    
    string decodeString(string s) {
        stack<string> stk;
        string cur = "";
        string num = "";
        
        for(char c : s) {
            if(isdigit(c)) {
                num += c;
            }
            else if(c == '[') {
                stk.push(cur);
                stk.push(num);
                cur = "";
                num = "";
            }
            else if(c == ']') {
                string oldNum = stk.top();
                stk.pop();
                string oldStr = stk.top();
                stk.pop();
                cur = oldStr + repeat(cur, stoi(oldNum));
            }
            else {
                cur += c;
            }
        }
        
        return cur;
    }
};

// maintain a stack
// when met [
//     push cur string
//     push number
//     re init
// when met ] 
//     pop * 2
//     cur str = old str + number * cur str
// else 
//     append to cur string
//     count num