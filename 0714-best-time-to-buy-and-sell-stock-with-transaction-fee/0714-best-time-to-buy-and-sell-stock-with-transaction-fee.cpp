class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;
        
        for(int p : prices) {
            buy = max(buy, sell - p);
            sell = max(sell, buy + p - fee);
        }
        
        return sell;
    }
};