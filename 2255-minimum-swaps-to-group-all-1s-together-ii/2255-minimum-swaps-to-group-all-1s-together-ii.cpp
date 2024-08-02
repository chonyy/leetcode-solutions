class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int numOnes = 0;

        for(int num : nums) {
            numOnes += num;
        }
        
        int n = nums.size();
        int l = 0;
        int r = 0;
        int res = INT_MAX;
        int zeros = 0;

        while(r < 2*n) {
            int curR = r % n;
            int curL = l % n;
            
            if(r - l == numOnes) {
                zeros -= nums[curL] == 0;
                l ++;
            }

            zeros += nums[curR] == 0;

            if(r - l + 1 == numOnes) {
                // cout << l << " " << r << endl;
                // cout << zeros << endl << endl;
                res = min(res, zeros);
            }

            r ++;
        }

        return res;
    }
};