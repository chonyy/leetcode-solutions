class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i ++) {
            int num = nums[i];
            for (int j = 1; j < num; j ++) {
                if ((j | j + 1) == num) {
                    res[i] = j;
                    break;
                }
            }

            if(res[i] == 0) {
                res[i] = -1;
            }
        }

        return res;
    }
};

// prime: no dividers


// 11 = 3
// 01
// 10


// 101 = 5
// 100
// 100

// 111 = 7
//  11
// 100



// even number = -1

