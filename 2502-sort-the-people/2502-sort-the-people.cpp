class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> pairs;
        int n = names.size();

        for(int i = 0; i < n; i ++) {
            pairs.push_back({heights[i], names[i]});
        }

        sort(pairs.begin(), pairs.end());

        vector<string> res;

        for(auto& pair : pairs) {
            res.push_back(pair.second);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};