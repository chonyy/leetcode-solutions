class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m+1, 0);
        int ans = 0;
        
        for(int i = 1; i <= n; i ++) {
            vector<int> temp(m+1, 0);
            for(int j = 1; j <= m; j ++) {
                if(nums1[i-1] == nums2[j-1]) {
                    temp[j] = dp[j-1] + 1;
                }
                else {
                    temp[j] = max(temp[j-1], dp[j]);
                }
            }
            swap(dp, temp);
        }
        
        return dp[m];
    }
};