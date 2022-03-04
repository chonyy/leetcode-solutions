class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> splits;
        int maxSplits = 0;
        
        for(auto& w : wall) {
            int sum = 0;
            int n = w.size();
            for(int i = 0; i < n-1; i ++) {
                sum += w[i];
                splits[sum] ++;
                maxSplits = max(maxSplits, splits[sum]);
            }
        }
        
        return wall.size() - maxSplits;
    }
};