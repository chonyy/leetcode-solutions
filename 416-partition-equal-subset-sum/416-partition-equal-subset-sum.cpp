class Solution {
public:
    bool checkPartition(vector<int>& nums, int idx, int target, vector<vector<int>>& memo) {
	// ending condition
	if(target == 0)
		return true;
	if(idx == nums.size() || target < 0)
		return false;

	if(memo[idx][target] != -1)
		return memo[idx][target];

	bool take = checkPartition(nums, idx+1, target - nums[idx], memo);
	bool notTake = checkPartition(nums, idx+1, target, memo);
	bool res = take || notTake;

	return memo[idx][target] = res;
}

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
vector<vector<int>> memo(n, vector<int>(target+1, -1));


return checkPartition(nums, 0, target, memo);
}



};