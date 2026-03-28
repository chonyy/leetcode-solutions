class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int arrow = 0;
        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && points[j][0] <= points[i][1]) {
                points[i][1] = min(points[i][1], points[j][1]); // shrink overlap space
                j ++;
            }

            i = j;
            arrow ++;
        }

        return arrow;
    }
};


// [10,16],[2,8],[1,6],[7,12]
// [1, 6], [2, 8], [7, 12], [10, 16]