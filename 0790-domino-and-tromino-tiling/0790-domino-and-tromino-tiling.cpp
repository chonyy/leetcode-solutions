class Solution {
public:
    int numTilings(int n) {
        vector<vector<long>> dp(n+1, vector<long>(2, 0));
        long pFill = 1;
        long pMore = 0;
        long ppFill = 1;
        long ppMore = 0;
        int mod = 7 + 1e9;
        
        for(int i = 2; i <= n; i ++) {
            int curFill = (pFill + ppFill + 2 * pMore) % mod;
            int curMore = (pMore + ppFill) % mod;
            ppFill = pFill;
            ppMore = pMore;
            pFill = curFill;
            pMore = curMore;
        }        
        
        return pFill;
    }
};

// xxxo
// xxxo

// xxoo
// xxii

// xxxo
// xxoo

// xxoo
// xxxo

// xxoo
// xxo

// xx
// xx