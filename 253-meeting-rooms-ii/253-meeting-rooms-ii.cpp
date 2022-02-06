class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto& inter : intervals) {
            if(pq.size() == 0)
                pq.push(inter[1]);
            else if(inter[0] < pq.top()) {
                pq.push(inter[1]);
            }
            else {
                pq.pop();
                pq.push(inter[1]);
            }
        }
        
        return pq.size();
    }
};