class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if (n == 1) {
            return cost[0];
        }

        if (n == 2) {
            return min(cost[0], cost[1]);
        }

        int prevOne = 0;
        int prevTwo = 0;

        for (int i = 2; i <= n; i ++) {
            int temp = min(prevOne + cost[i-1], prevTwo + cost[i-2]);
            prevTwo = prevOne;
            prevOne = temp;
        }

        return prevOne;
    }
};