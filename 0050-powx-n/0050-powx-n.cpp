class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long newN = n;
        if(newN < 0) newN = -newN;
        while(newN > 0) {
            if(newN % 2) {
                ans = ans * x;
                newN --;
            }
            else {
                x = x * x;
                newN /= 2;
            }
        }

        if(n < 0) ans = (double)(1.0) / ans;

        return ans;
    }
};