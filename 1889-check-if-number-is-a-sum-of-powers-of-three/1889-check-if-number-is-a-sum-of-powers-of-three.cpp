class Solution {
public:
    bool checkPowersOfThree(int n) {
        int largestPow = 0;

        while(pow(3, largestPow) <= n) {
            largestPow ++;
        }
        largestPow --;

        for(int i = largestPow; i >= 0; i --) {
            int curPow = pow(3, i);

            if(curPow > n) {
                continue;
            }

            n -= curPow;

            if(n == 0) {
                return true;
            }
        }

        return n == 0;
    }
};