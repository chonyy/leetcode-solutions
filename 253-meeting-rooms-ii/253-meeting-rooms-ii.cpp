class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        pq.push(intervals[0][1]);
        int res = 0;
        
        for(int i = 1; i < n; i ++) {
            auto earliest = pq.top();
            auto& cur = intervals[i];
            
            if(cur[0] >= earliest) {
                pq.pop();
            }
            
            pq.push(cur[1]);
        }
        
        return pq.size();
    }
};