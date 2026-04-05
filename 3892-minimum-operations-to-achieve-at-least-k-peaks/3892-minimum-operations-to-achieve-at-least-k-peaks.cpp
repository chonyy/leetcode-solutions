class Solution {
public:
    int INF = pow(10, 9);
    vector<vector<int>> dp;

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        dp = vector<vector<int>>(n, vector<int>(k+1, -1));
        int first = solve(nums, 0, n-1, k);
        dp = vector<vector<int>>(n, vector<int>(k+1, -1));
        int last = solve(nums, 1, n, k);

        return min(first, last) >= INF ? -1 : min(first, last);
    }

    int cost(vector<int>& nums, int idx) {
        int prev = idx == 0 ? nums.size() - 1 : idx - 1;
        int next = (idx + 1) % nums.size();
        int diff = max(nums[prev], nums[next]) - nums[idx];
        return diff >= 0 ? diff + 1 : 0;
    }

    int solve(vector<int>& nums, int idx, int end, int k) {
        if (k == 0) {
            return 0;
        }

        if (idx >= end) {
            return INF;
        }

        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int take = cost(nums, idx) + solve(nums, idx + 2, end, k -1);
        int leave = solve(nums, idx + 1, end, k);

        int res = min(take, leave);

        return dp[idx][k] = res;
    }
};