class Solution {
public:
    bool checkValidString(string s) {
        int minCount = 0;
        int maxCount = 0;
        
        for(char c : s) {
            if(c == '(') {
                minCount ++;
                maxCount ++;
            }
            else if(c == ')') {
                minCount --;
                maxCount --;
            }
            else {
                minCount --;
                maxCount ++;
            }
            
            if(maxCount < 0)
                return false;
            
            minCount = max(minCount, 0);
        }
        
        return minCount == 0;
    }
};