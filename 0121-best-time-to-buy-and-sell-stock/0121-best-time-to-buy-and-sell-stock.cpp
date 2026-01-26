class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevMin = prices[0];
        int res = 0;

        for (int p : prices) {
            res = max(res, p - prevMin);
            prevMin = min(prevMin, p);
        }

        return res;
    }
};