class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        int i = 1;

        while (i < n) {
            auto& prev = res.back();
            
            while (i < n && prev[1] >= intervals[i][0]) {
                prev[1] = max(prev[1], intervals[i][1]);
                i ++;
            }

            if (i < n) {
                res.push_back(intervals[i]);
            }
            
            i ++;
        }

        return res;
    }
};