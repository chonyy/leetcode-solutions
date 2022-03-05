class Solution {
public:
    bool differByOne(vector<string>& dict) {
        const int MOD = 1'000'000'007; 
        vector<int> hs; 
        for (auto& word : dict) {
            long val = 0; 
            for (auto& ch : word) val = (26*val + ch - 'a') % MOD; 
            hs.push_back(val); 
        }
        
        int m = dict.size(), n = dict[0].size(); 
        long mult = 1l; 
        for (int j = n-1; j >= 0; --j) {
            unordered_map<int, vector<int>> seen; 
            for (int i = 0; i < m; ++i) {
                int val = (hs[i] - (dict[i][j] - 'a')*mult + 26l*MOD) % MOD; 
                if (seen.count(val)) 
                    for (auto& ii : seen[val]) 
                        if (dict[ii].substr(0, j) == dict[i].substr(0, j) && dict[ii].substr(j+1, n-j-1) == dict[i].substr(j+1, n-j-1)) return true; 
                seen[val].push_back(i); 
            }
            mult = (26 * mult) % MOD; 
        }
        return false; 
    }
};