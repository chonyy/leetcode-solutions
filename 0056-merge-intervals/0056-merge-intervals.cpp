class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && intervals[j][0] <= intervals[i][1]) {
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                j ++;
            }

            res.push_back(intervals[i]);
            i = j;
        }

        return res;
    }
};