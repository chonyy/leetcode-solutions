class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();
        vector<vector<int>> res;
        
        if(n == 0) {
            return {newInterval};
        }

        while(i < n) {
            auto& inter = intervals[i];
            if(newInterval[0] <= inter[1])
                break;
            res.push_back(inter);
            i ++;
        }
        
        while(i < n) {
            auto& inter = intervals[i];
            if(newInterval[1] < inter[0]) {
                break;
            }
            
            newInterval[0] = min(newInterval[0], inter[0]);
            newInterval[1] = max(newInterval[1], inter[1]);
                
            i ++;
        }
        
        res.push_back({newInterval});
        
        while(i < n) {
            res.push_back(intervals[i]);
            i ++;
        }
        
        return res;
    }
};

// push all nonoverlapping
// keep track of min and max of overlapping
// push remain