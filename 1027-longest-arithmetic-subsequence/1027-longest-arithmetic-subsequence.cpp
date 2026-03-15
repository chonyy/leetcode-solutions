class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return n;
        }

        unordered_map<int, unordered_map<int,int>> dp;

        int res = 2;

        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                int diff = nums[i] - nums[j];
                
                if (dp[j][diff] == 0) {
                    dp[j][diff] = 1;
                }

                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                res = max(res, dp[i][diff]);
            }
        }

        return res;
    }
};

// 20,1,15,3,10,5,8