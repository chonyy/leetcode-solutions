class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }        

        if(sum % 2) {
            return false;
        }

        int n = nums.size();
        int target = sum / 2;
        
        vector<bool> dp(target + 1, false);
	dp[0] = true;

	for(int num : nums) {
		for(int i = target; i >= 0; i --) {
			int need = i - num;
			if(need < 0)
				continue;
			dp[i] = dp[i] || dp[need];
}
}

return dp[target];
}

};