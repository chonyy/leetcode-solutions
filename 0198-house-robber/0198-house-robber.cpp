class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prevOne = 0;
        int prevTwo = 0;

        for (int i = 0; i < n; i ++) {
            int temp = max(prevOne, prevTwo + nums[i]);
            prevTwo = prevOne;
            prevOne = temp;
        }

        return prevOne;
    }
};


// 1, 2, 3, 1


// rob = 0
// notRob = 0

