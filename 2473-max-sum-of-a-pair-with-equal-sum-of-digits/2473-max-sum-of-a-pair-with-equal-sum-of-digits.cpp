class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res = 0;
        vector<int> m(82);

        for(int num : nums) {
            int sum = sumDigits(num);
            
            if(m[sum] > 0) {
                res = max(res, m[sum] + num);
            }

            m[sum] = max(m[sum], num);
        }

        return res == 0 ? -1 : res;
    }

    int sumDigits(int num) {
        int res = 0;

        while(num) {
            res += num % 10;
            num /= 10;
        }

        return res;
    }
};