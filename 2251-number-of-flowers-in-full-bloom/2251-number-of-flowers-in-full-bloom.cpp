class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> diff;

        for (auto& flower : flowers) {
            diff[flower[0]] += 1;
            diff[flower[1] + 1] -= 1;
        }

        vector<int> position = {0};
        vector<int> prefix = {0};

        int cur = 0;
        for (auto& entry : diff) {
            cur += entry.second;
            position.push_back(entry.first);
            prefix.push_back(cur);
        }

        vector<int> res;
        for (int p : people) {
            auto it = upper_bound(position.begin(), position.end(), p);
            int idx = it - position.begin() - 1;
            res.push_back(prefix[idx]);
        }

        return res;
    }
};