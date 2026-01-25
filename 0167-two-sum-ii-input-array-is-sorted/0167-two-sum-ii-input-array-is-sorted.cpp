class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int curSum = numbers[l] + numbers[r];
            if (curSum == target) {
                return {l+1, r+1};
            }

            if (curSum > target) { // too big, need to go small
                r --;
            }

            if (curSum < target) {
                l ++;
            }
        }

        return {};
    }
};

// 2 7 8
// l   r

// target + 9