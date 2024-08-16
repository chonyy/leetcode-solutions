class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int curMin = arrays[0].front();
        int curMax = arrays[0].back();
        int n = arrays.size();
        int res = 0;       

        for(int i = 1; i < n; i ++) {
            auto& arr = arrays[i];


            res = max(res, curMax - arr.front());
            res = max(res, arr.back() - curMin);

            curMin = min(curMin, arr.front());
            curMax = max(curMax, arr.back());
        }
        
        return res;
    }
};