class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> nums(n, 1);
        
        for(int i = 1; i < n; i ++) {
            int nextNum = min(
                min(nums[i2] * 2, nums[i3] * 3),
                nums[i5] * 5
            );
            nums[i] = nextNum;
            // cout << nextNum << endl;
            // cout << i2 << " " << i3 << " " << i5 << endl;

            // cout << nums[i2] * i2 << endl;

            if(nextNum == (nums[i2] * 2))
                i2 ++;
            if(nextNum == (nums[i3] * 3))
                i3 ++;
            if(nextNum == (nums[i5] * 5))
                i5 ++;
        }

        return nums[n-1];
    }
};