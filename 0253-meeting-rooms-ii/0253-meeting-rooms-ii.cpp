class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // min heap
        priority_queue<int, vector<int>, greater<>> pq;
        sort(intervals.begin(), intervals.end());

        for (auto& inter : intervals) {
            if (pq.empty()) {
                pq.push(inter[1]);
                continue;
            }

            if (inter[0] < pq.top()) {
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