class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }

    int atMost(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();

        unordered_map<int,int> count;
        int res = 0;

        // cout << "K " << k << endl;

        while (r < n) {
            // add nums[r] to count
            // if counts.size() <= K, res += r - l + 1
            count[nums[r]] ++;

            // if size > k, remove count with l. If count is zero, erase from map
            while (count.size() > k) {
                count[nums[l]] --;

                if (count[nums[l]] == 0) {
                    count.erase(nums[l]);
                }

                l ++;
            }

            res += r - l + 1;
            r ++;
        }

        // cout << res << endl;
        return res;
    }
};