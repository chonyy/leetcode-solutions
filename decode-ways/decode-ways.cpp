class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        int two = 1;
        int one = s[0] == '0' ? 0 : 1;
        
        for(int i = 2; i <= n; i ++) {
            int oneDigit = stoi(s.substr(i-1, 1));
            int twoDigit = stoi(s.substr(i-2, 2));
            int dp = 0;
            
            if(oneDigit >= 1 && oneDigit <= 9) {
                dp += one;
            }
            if(twoDigit >= 10 && twoDigit <= 26) {
                dp += two;
            }
            
            two = one;
            one = dp;
        }
            
        return one;
    }
};