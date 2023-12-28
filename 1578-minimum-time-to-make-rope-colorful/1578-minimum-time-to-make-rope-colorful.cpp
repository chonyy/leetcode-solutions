class Solution {
public:
    int minCost(string S, vector<int>& C) {
        int n = S.size();
        int curMax = 0;
        int res = 0;
        for(int i = 0; i < n; i ++) {
            if(i > 0 && S[i] != S[i-1]) {
                curMax = 0;
            }
            res += min(C[i], curMax);
            curMax = max(curMax, C[i]);
        }

        return res;
    }
};