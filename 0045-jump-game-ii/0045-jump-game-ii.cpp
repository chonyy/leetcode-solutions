class Solution {
public:
    int jump(vector<int>& nums) {
        int curReach = 0;
        int maxReach = 0;
        int step = 0;

        if (nums.size() == 1) {
            return 0;
        }

        for (int i = 0; i < nums.size(); i ++) {
            // update max reach
            maxReach = max(maxReach, i + nums[i]);

            // add step if at curReach
            if (i == curReach) {
                step ++;
                curReach = maxReach;
            }

            // exit early if reach last idx
            if (curReach >= nums.size()-1) {
                return step;
            }
        }

        return step;
    }
};


// 2,3,1,1,4
//     i

// curReach = 0
// maxReach = 0
// step = 0


// curReach = 2
// maxReach = 2
// step = 1

// curReach = 2
// maxReach = 4
// step = 1

// curReach = 4
// maxReach = 4
// step = 2



// update max Reach

// if idx == curReach
//     step ++
//     curReach = maxReach


// 0 1 1
//     2 2 2
//       2
//         3