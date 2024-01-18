class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        
        if(n == 2)
            return 2;
        
        int prevTwo = 1;
        int prevOne = 2;
        
        for(int i = 3; i <= n; i ++) {
            int temp = prevOne + prevTwo;
            prevTwo = prevOne;
            prevOne = temp;
        }
        
        return prevOne;
    }
};