class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols, 1000000));
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                }
                else {
                    if(i > 0)
                        dist[i][j] = min(dist[i][j], dist[i-1][j]+1);
                    if(j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j-1]+1);
                }
            }
        }
        
        for(int i = rows-1; i >= 0; i --) {
            for(int j = cols-1; j >= 0; j --) {
                if(i < rows-1)
                    dist[i][j] = min(dist[i][j], dist[i+1][j]+1);
                if(j < cols-1)
                    dist[i][j] = min(dist[i][j], dist[i][j+1]+1);
            }
        }
        
        return dist;
    }
};