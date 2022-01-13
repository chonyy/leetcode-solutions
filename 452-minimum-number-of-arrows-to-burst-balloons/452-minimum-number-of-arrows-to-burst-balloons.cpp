class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        };
        sort(points.begin(), points.end(), cmp);
        int n = points.size();
        int arrows = 1;
        int shoot = points[0][1];
        
        for(int i = 1; i < n ; i++) {
            auto& point = points[i];
            // cout << shoot << " " << point[0] << endl;
            if(point[0] > shoot) {
                shoot = point[1];
                arrows ++;
            }
        }
        
        return arrows;
    }
};