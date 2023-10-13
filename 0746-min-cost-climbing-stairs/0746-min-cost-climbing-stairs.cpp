class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int prevTwo = 0;
        int prevOne = 0;
        
        for(int i = 2; i <= n; i ++) {
            int temp = min(prevOne + cost[i-1], prevTwo + cost[i-2]);
            prevTwo = prevOne;
            prevOne = temp;
        }
        
        return prevOne;
    }
};