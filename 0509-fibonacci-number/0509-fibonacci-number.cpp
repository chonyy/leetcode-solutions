class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        int prevOne = 1;
        int prevTwo = 0;
        for (int i = 2; i <= n; i ++) {
            int temp = prevOne + prevTwo;
            prevTwo = prevOne;
            prevOne = temp;
        }

        return prevOne;
    }
};