class Solution {
public:
    int dp[101][21][101] = {};
    int MAX =  9999999;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
            int ans = solve(houses, cost, m, n, target, 0, 0);
            return ans < MAX ? ans : -1;
    }
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int p){
        if(i == m || target < 0){
            if(target == 0)
                return 0;
            
            return MAX;
        }
         if(dp[i][p][target] != 0)
             return dp[i][p][target];
        
        int ans = MAX;
        if(houses[i] == 0){
            for(int k=1; k<=n; k++){ //k->new color
                ans = std::min(ans, solve(houses, cost, m, n, target - (k != p) , i+1, k) + cost[i][k-1]);   
            }
        }else{
            ans = solve(houses, cost, m, n, target - (houses[i] != p), i+1, houses[i]);
        }
        return dp[i][p][target] = ans;
    }
};