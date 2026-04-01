class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);

        int prevOne = 0;
        int prevTwo = 0;
        
        prevTwo = 1;
        prevOne =  s[0] == '0' ? 0 : 1;
        
        for(int i = 2; i <= n; i ++) {
            int oneNum = stoi(s.substr(i-1, 1));
            int twoNum = stoi(s.substr(i-2, 2));

            int ways = 0;
            
            if(oneNum > 0 && oneNum <= 9) {
                ways += prevOne;
            }
            if(twoNum >= 10 && twoNum <= 26) {
                ways += prevTwo;
            }

            prevTwo = prevOne;
            prevOne = ways;
        }
        
        return prevOne;
    }
};

// 0
    
// 226


//      202
//        i

// dp: 1 1 1 1