class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        int prevOne = 2;
        int prevTwo = 1;

        for (int i = 0; i < n-2; i ++) {
            int temp = prevOne + prevTwo;
            prevTwo = prevOne;
            prevOne = temp;
        }

        return prevOne;
    }
};