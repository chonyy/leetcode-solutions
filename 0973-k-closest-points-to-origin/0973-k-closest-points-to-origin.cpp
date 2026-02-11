class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int,int>& p1, pair<int,int>& p2) {
            int distance1 = p1.first * p1.first + p1.second * p1.second;
            int distance2 = p2.first * p2.first + p2.second * p2.second;

            return distance1 < distance2;
        };

        // max heap based on distance
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for (auto& p : points) {
            pq.push({p[0], p[1]});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }

        return res;
    }
};