class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // sort
        // loop k from end
        // check l and r
        // if l + r > k
        //   ans += r - l
        //.  r --
        // else
        //.  l ++
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = n - 1;
        int res = 0;

        while (k >= 2) {
            int l = 0;
            int r = k - 1;

            // cout << "k " << k << endl;
            while (l < r) {
                // cout << l << " " << r << endl;
                if ((nums[l] + nums[r]) > nums[k]) {
                    res += r - l;
                    // cout << "add " << r - l << endl;
                    r --;
                }
                else {
                    l ++;
                }
            }
            k --;
        }

        return res;
    }
};

// 2,2,3,4
//       k
// l
//     r