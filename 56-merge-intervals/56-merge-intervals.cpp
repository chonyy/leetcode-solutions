class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        
        if(n == 0)
            return {};
        
        sort(intervals.begin(), intervals.end());
        
        res.push_back(intervals[0]);
        for(int i = 1; i < n; i ++) {
            auto& inter = intervals[i];
            
            if(inter[0] > res.back()[1]) {
                res.push_back(inter);
            }
            else {
                res.back()[1] = max(res.back()[1], inter[1]);
            }
        }
        
        
        return res;
    }
};