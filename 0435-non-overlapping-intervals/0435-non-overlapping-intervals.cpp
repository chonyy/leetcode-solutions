class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        sort(intervals.begin(), intervals.end());

        if (n == 0) {
            return 0;
        }

        int lastIntervalEnd = intervals[0][1];

        for (int i = 1; i < n; i ++) {
            vector<int>& inter = intervals[i];

            if (inter[0] < lastIntervalEnd) {
                lastIntervalEnd = min(lastIntervalEnd, inter[1]);
                res ++;
            }
            else {
                lastIntervalEnd = inter[1];
            }
        }

        return res;
    }
};

// [1,2],[1,3],[2,3],[3,4]



// [1,5] [2,3] [4,8] [9,10]
// res = 1




// 1          11
//   2            12
//            11  12
// 1                               100


// [0,   2]
// [. 1,    3]
// [.    2,       4]
// [.       3,         5]
// [              4,               6]