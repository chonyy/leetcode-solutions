class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> digitSumMax;
        int res = -1;

        for (int num : nums) {
            int sum = digitSum(num);

            if (digitSumMax[sum] > 0) {
                res = max(res, num + digitSumMax[sum]);
            }

            digitSumMax[sum] = max(digitSumMax[sum], num);
        }

        return res;
    }

    int digitSum(int num) {
        int res = 0;

        while (num) {
            res += num % 10;
            num = num / 10;
        }

        return res;
    }
};