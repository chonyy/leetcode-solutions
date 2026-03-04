class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }

        sort(nums.begin(), nums.end());
        kSum(nums, 4, (long long) target, 0);

        return res;
    }

    void kSum(vector<int>& nums, int k, long long target, int idx) {
        if (k == 2) {
            int l = idx;
            int r = nums.size() - 1;
            // cout << "target " << target << endl;

            while (l < r) {
                long long sum = (long long)nums[l] + nums[r];
                // cout << nums[l] << " + " << nums[r] << " = " << sum << endl; 

                if (sum == target) {
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();

                    r --;
                    l ++;

                    while (l < r && nums[l] == nums[l-1]) {
                        l ++;
                    }

                    while (l < r && nums[r] == nums[r+1]) {
                        r --;
                    }   
                }
                else if (sum > target) {
                    r --;
                }
                else {
                    l ++;
                }
            }

            return;
        }

        for (int i = idx; i < nums.size() - (k-1); i ++) {
            if (i > idx && nums[i] == nums[i-1]) {
                continue;
            }

            // pick a number
            // target = target -= number
            // cout << "pick " << nums[i] << endl;
            temp.push_back(nums[i]);
            kSum(nums, k-1, target - nums[i], i+1);
            temp.pop_back();
        }
    }
};