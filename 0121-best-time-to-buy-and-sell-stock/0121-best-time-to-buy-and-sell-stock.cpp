class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int localMin = prices[0];
        int n = prices.size();
        
        for(int i = 0; i < n; i ++) {
            if(prices[i] < localMin) {
                localMin = min(localMin, prices[i]);
            }
            
            ans = max(ans, prices[i] - localMin);
        }
        
        return ans;
    }
};