class Solution {
public:

    int tribonacci(int n) {
        if(n < 2)
            return n;
        if(n == 2)
            return 1;
        
        int prevOne = 1;
        int prevTwo = 1;
        int prevThree = 0;

        for (int i = 3; i <= n; i ++) {
            int temp = prevThree + prevTwo + prevOne;

            prevThree = prevTwo;
            prevTwo = prevOne;
            prevOne = temp;
        }

        return prevOne;
    }
};