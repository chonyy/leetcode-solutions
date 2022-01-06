class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cur(1001, 0);
        
        for(auto trip : trips) {
            int pass = trip[0];
            cur[trip[1]] += pass;
            cur[trip[2]] -= pass;
        }
        
        if(cur[0] > capacity)
            return false;
        
        for(int i = 1; i <= 1000; i ++) {
            cur[i] += cur[i-1];
            // cout << i << " " << cur[i] << endl;
            if(cur[i] > capacity)
                return false;
        }
        
        return true;
    }
};