class Solution {
public:
    bool judgeSquareSum(int c) {
        int m = sqrt(c);
        
        for(long long i = 0; i <= m; i ++) {
            int diff = c - i * i;
            long long b = round(sqrt(diff));
            if(i * i + b * b == c) {
                return true;
            }
        }
        
        return false;
    }
};