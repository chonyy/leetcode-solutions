class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int maxDays = 100001;

        // sort by startTime
        sort(events.begin(), events.end());
        int idx = 0;
        int n = events.size();
        int res = 0;
        priority_queue<int, vector<int>, greater<>> endTimes;

        for (int i = 1; i <= maxDays; i ++) {
            // remove ended meetings
            while (!endTimes.empty() && endTimes.top() < i) {
                endTimes.pop();
            }

            // put new event in minHeap
            while (idx < n && events[idx][0] == i) {
                endTimes.push(events[idx][1]);
                idx ++;
            }

            // skip if no available
            if (endTimes.empty()) {
                continue;
            }

            // pick top from minHeap
            endTimes.pop();
            res ++;
        }

        return res;
    }
};