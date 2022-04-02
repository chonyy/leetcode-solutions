class Solution {
public:
    long long numberOfWays(string s) {
        int ones = 0;
        int zeros = 0;
        
        for(char c : s) {
            if(c == '1') {
                ones ++;
            }
            else {
                zeros ++;
            }
        }
        
        int oneBefore = 0;
        int zeroBefore = 0;
        long long res = 0;
        
        for(char c : s) {
            if(c == '1') {
                res += zeroBefore * zeros;
                oneBefore ++;
                ones --;
            }
            else {
                res += oneBefore * ones;
                zeroBefore ++;
                zeros --;
            }
        }
        
        return res;
    }
};