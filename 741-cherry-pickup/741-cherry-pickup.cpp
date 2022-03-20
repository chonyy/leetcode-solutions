class Solution {
public:
    int n;
    int solve(vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp, int r1, int c1, int r2, int c2) {
        // cout << "1" << endl;
        // cout << r1 << " " << c1 << endl;
        // cout << "2" << endl;
        // cout << r2 << " " << c2 << endl;
        
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n) {
            // cout << "bound" << endl;
            return -1;
        }
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            // cout << "block" << endl;
            return -1;
        }
        
        // if reach answer
        if(r1 == n-1 && c1 == n-1) {
            // cout << "ans" << endl;
            return grid[n-1][n-1];
        }
        if(r2 == n-1 && c2 == n-1) {
            // cout << "ans" << endl;
            return grid[n-1][n-1];
        }
        
        // if calculated
        if(dp[r1][c1][r2][c2] != INT_MIN) {
            // cout << "cal" << endl;
            return dp[r1][c1][r2][c2];
        }
        
        // count cherries
        int cherries = 0;
        
        if(r1 == r2 && c1 == c2) {
            cherries += grid[r1][c1];
        }
        else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }
        
        int theMax = INT_MIN;
        theMax = max(theMax, solve(grid, dp, r1+1, c1, r2+1, c2));
        theMax = max(theMax, solve(grid, dp, r1, c1+1, r2+1, c2));
        theMax = max(theMax, solve(grid, dp, r1+1, c1, r2, c2+1));
        theMax = max(theMax, solve(grid, dp, r1, c1+1, r2, c2+1));
        
        if(theMax < 0) {
            return dp[r1][c1][r2][c2] = -1;
        }
        
        return dp[r1][c1][r2][c2] = cherries + theMax;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,INT_MIN))));
        return max(solve(grid, dp, 0, 0, 0, 0), 0);
    }
};