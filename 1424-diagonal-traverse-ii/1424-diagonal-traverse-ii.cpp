class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> diag;
        vector<int> res;
        
        int rows = nums.size();
        int maxLevel = 0;
        
        // store with diag key
        for(int i = 0; i < rows; i ++) {
            int cols = nums[i].size();
            for(int j = 0; j < cols; j ++) {
                int key = i + j;
                maxLevel = max(maxLevel, key);
                diag[key].push_back(nums[i][j]);
            }
        }
        
        // push to res from diag
        for(int i = 0; i <= maxLevel; i ++) {
            int size = diag[i].size();
            for(int j = size-1; j >= 0; j --) {
                res.push_back(diag[i][j]);
            }
        }
        
        
        return res;
    }
};