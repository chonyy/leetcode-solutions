class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // keep track of left and right
        // when we meet left, increment left count
        // when we meet right, if left count > 0, increment valid count, decrease left count
        
        int left = 0;
        int valid = 0;
        
        for(char c : s) {
            if(c == '(') {
                left ++;
            }
            else if(c == ')' && left > 0) {
                valid ++;
                left --;
            }
        }
        
        string res = "";
        int leftUsed = 0;
        int leftRemain = valid;
        
        for(char c : s) {
            if(c == ')') {
                if(leftUsed == 0) {
                    continue;
                }
                else {
                    leftUsed --;
                }
            }
            if(c == '(') {
                if(leftRemain == 0) {
                    continue;
                }
                else {
                    leftRemain --;
                    leftUsed ++;
                }
            }
            
            res += c;
        }
        
        return res;
    }
};