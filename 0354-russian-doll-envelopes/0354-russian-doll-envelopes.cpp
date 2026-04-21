class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }

            return v1[0] < v2[0];
        };

        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> heights;

        for (auto& e : envelopes) {
            auto lo = lower_bound(heights.begin(), heights.end(), e[1]);
            if (lo == heights.end()) {
                heights.push_back(e[1]);
            }
            else {
                *lo = e[1];
            }
        }

        return heights.size();
    }
};