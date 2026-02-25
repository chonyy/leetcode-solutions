class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        for (int j = 0; j < 3; j ++) {
            int t = target[j];
            int found = false;
            for (int i = 0; i < n; i ++) {
                auto& trip = triplets[i];

                if (trip[0] > target[0] || trip[1] > target[1] || trip[2] > target[2]) {
                    continue;
                }

                found = found || trip[j] == t;
            }

            if (found == false) {
                return false;
            }
        }

        return true;
    }
};