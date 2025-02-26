class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int posSum = 0;
        int negSum = 0;
        int res = 0;

        for(int num : nums) {
            // positive
            if(posSum + num > num) {
                posSum = posSum + num;
            }
            else {
                posSum = num;
            }

            // negative
            if(negSum + num < num) {
                negSum = negSum + num;
            }
            else {
                negSum = num;
            }

            // cout << posSum << endl;
            // cout << negSum << endl;

            res = max(res, max(abs(negSum), abs(posSum)));
        }

        return res;
    }
};