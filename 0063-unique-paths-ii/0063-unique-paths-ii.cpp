class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (obstacleGrid[i][j] == -1) {
                    continue;
                }
                if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = 1;
                    continue;
                }

                int top = (i == 0 || obstacleGrid[i-1][j] == -1) ? 0 : obstacleGrid[i-1][j];
                int left = (j == 0 || obstacleGrid[i][j-1] == -1) ? 0 : obstacleGrid[i][j-1];

                // cout << top << " " << left << endl;

                obstacleGrid[i][j] = top + left;
            }
        }

        return obstacleGrid[rows-1][cols-1] == -1 ? 0 : obstacleGrid[rows-1][cols-1];
    }
};