class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp = [](vector<int> v1, vector<int> v2) {
            return v1[1] < v2[1];
        };
        
        sort(pairs.begin(), pairs.end(), cmp);
        int prev = INT_MIN;
        int ans = 0;
        int n = pairs.size();
        
        for(int i = 0; i < n; i ++) {
            // if starting is larger than prev, then add it
            auto& pair = pairs[i];
            if(pair[0] <= prev)
                continue;
            
            prev = pair[1];
            ans ++;
        }
        
        return ans;
    }
};

// [1, 2] [2, 3] [3, 4] [3, 6]