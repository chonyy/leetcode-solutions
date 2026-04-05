class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curMin = INT_MAX;

        for (int p : prices) {
            res = max(res, p - curMin);
            curMin = min(p, curMin);
        }

        return res;
    }
};