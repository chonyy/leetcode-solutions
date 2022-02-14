class Solution {
public:
    int count(vector<int>& arr) {
        int length = 0;
        int res = 0;
        
        for(int num : arr) {            
            if(num == 0) {
                length = 0;
            }
            else {
                length ++;
            }
            res += length;
        }
        
        return res;
    }
    
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int res = 0;
        
        for(int up = 0; up < rows; up ++) {
            vector<int> arr(cols, 1);
            for(int down = up; down < rows; down ++) {
                for(int j = 0; j < cols; j ++) {
                    arr[j] = arr[j] & mat[down][j];
                }
                
                res += count(arr);
            }
        }
        
        return res;
    }
};