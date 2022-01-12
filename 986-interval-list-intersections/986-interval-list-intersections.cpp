class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        
        int p1 = 0;
        int p2 = 0;
        
        int n = firstList.size();
        int m = secondList.size();
        
        while(p1 < n && p2 < m) {
            int maxStart = max(firstList[p1][0], secondList[p2][0]);
            int minEnd = min(firstList[p1][1], secondList[p2][1]);
            
            if(maxStart <= minEnd) { // overlap
                res.push_back({maxStart, minEnd});
            }
            
            if(minEnd == firstList[p1][1]) {
                p1 ++;
            }
            else {
                p2 ++;
            }
        }
        
        return res;
    }
};