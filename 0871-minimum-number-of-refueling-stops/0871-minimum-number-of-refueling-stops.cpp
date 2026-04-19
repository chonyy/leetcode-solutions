class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        priority_queue<int> pq;
        int cur = startFuel, res = 0;

        for (auto& s : stations) {
            int pos = s[0];
            int fuel = s[1];

            while (!pq.empty() && cur < pos) {
                cur += pq.top(); pq.pop();
                res++;
            }

            if (cur < pos) {
                return -1;
            }
            
            pq.push(fuel);
        }

        return res;
    }
};