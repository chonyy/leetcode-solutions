class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIndex = 0;
        int twoIndex = nums.size() - 1;

        for (int i = 0; i < nums.size(); i ++) {
            if (i > twoIndex) {
                break;
            }

            if (nums[i] == 0) {
                swap(nums[zeroIndex], nums[i]);
                zeroIndex++;
            }

            if (nums[i] == 2) {
                swap(nums[twoIndex], nums[i]);
                twoIndex --;
                i --; // avoid ignoring new zeros
            }
        }
    }
};

// 0,0,1,1,2,2
//   o 
//       t

//         i  