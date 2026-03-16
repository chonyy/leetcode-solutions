class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) ones1.push_back({i, j});
                if (img2[i][j]) ones2.push_back({i, j});
            }
        }
        
        unordered_map<int, int> count;
        for (auto [r1, c1] : ones1) {
            for (auto [r2, c2] : ones2) {
                int shift = (r1 - r2) * 100 + (c1 - c2);  // Encode as single int
                count[shift]++;
            }
        }
        
        int result = 0;
        for (auto [s, c] : count) {
            result = max(result, c);
        }
        
        return result;
    }
};