class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res = 0;
        int cur = startFuel;

        // max heap
        priority_queue<int> pq;

        for (auto& station : stations) {
            int pos = station[0];
            int fuel = station[1];

            // add fuel until enough
            while (!pq.empty() && cur < pos) {
                cur += pq.top();
                // cout << "add " << pq.top() << endl;
                pq.pop();
                res ++;
            }

            if (pq.empty() && cur < pos) {
                return -1;
            }

            pq.push(fuel);
        }

        // add fuel until enough
        while (!pq.empty() && cur < target) {
            cur += pq.top();
            // cout << "add " << pq.top() << endl;
            pq.pop();
            res ++;
        }

        if (cur < target) {
            return -1;
        }

        return res;
    }
};