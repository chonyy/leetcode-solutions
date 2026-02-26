class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int idx = 0;

        if (n == 0) {
            return {newInterval};
        }

        // step1: merge beginning non-overlap
        while (idx < n && intervals[idx][1] < newInterval[0]) {
            res.push_back(intervals[idx]);
            idx ++;
        }

        int intervalStart = INT_MAX;
        int intervalEnd = -1;

        // step2: merge overlaps
        while (idx < n && intervals[idx][0] <= newInterval[1]) {
            intervalStart = min(intervalStart, intervals[idx][0]);
            intervalStart = min(intervalStart, newInterval[0]);

            intervalEnd = max(intervalEnd, intervals[idx][1]);
            intervalEnd = max(intervalEnd, newInterval[1]);
            idx ++;
        }
        if (intervalStart != INT_MAX) {
            res.push_back({intervalStart, intervalEnd});
        }
        else {
            res.push_back(newInterval);
        }

        // step3: merge final non-overlap
        while (idx < n) {
            res.push_back(intervals[idx]);
            idx ++;
        }

        return res;
    }
};

// [1,2],[3,5],[6,7],[8,10],[12,16]
//                            i

// [4,8]

// intervalStart = 3
// intervalEnd = 10

// res: [1,2][3,10][12,16]


// [1,3],[6,9]
//  x

// [2,5]

// [1,5]

// loop through intervals to find start
//     start = inter1.end >= inter2.start

// start merging
//     skip until inter1.start > inter2.end or the end
//     insert [originalStart, max(inter1.end, inter2.end)]



// [1,2],[3,5],[6,7],[8,10],[12,16]
//                     i

// [4,8]


// [1,2][3, 10][12,16]

//      1      5
//   0  


//       o     o
// n  n   