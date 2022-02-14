class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int n = heights.size();
        int curMax = 0;
        
        for(int i = n-1; i >= 0; i --) {
            int h = heights[i];
            // cout << h << " " << curMax << endl;
            if(h > curMax) {
                // cout << "fuck" <<endl;
                curMax = h;
                res.push_back(i);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
