class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();

        vector<long long> left(cols, 0);
        vector<long long> right(cols, 0);

        vector<long long> newPoints(cols, 0);

        for(int j = 0; j < cols; j ++) {
            newPoints[j] = points[0][j];
        }

        for(int i = 1; i < rows; i ++) {

            if(i > 0) {
                // populate left
                for(int j = 0; j < cols; j ++) {
                    int prev = max(0, j-1);
                    left[j] = max(left[prev] - 1, newPoints[j]);
                }

                // populate right
                for(int j = cols-1; j >= 0; j --) {
                    int prev = min(cols-1, j+1);
                    right[j] = max(right[prev] - 1, newPoints[j]);
                }
            }

            for(int j = 0; j < cols; j ++) {
                newPoints[j] = points[i][j] + max(left[j], right[j]);
                // cout << points[i][j] << " ";
            }
            // cout << endl;
        }


        long long res = 0;
        for(int i = 0; i < cols; i ++) {
            res = max(res, newPoints[i]);
        }

        return res;
    }
};