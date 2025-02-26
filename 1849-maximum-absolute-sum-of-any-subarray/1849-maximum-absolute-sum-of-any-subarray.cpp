class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int posSum = 0;
        int negSum = 0;
        int res = 0;

        for(int num : nums) {
            // positive
            posSum = max(posSum + num, num);
            negSum = min(negSum + num, num);

            res = max(res, max(abs(negSum), abs(posSum)));
        }

        return res;
    }
};