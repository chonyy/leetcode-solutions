class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxx = 0;
        unordered_map<char, int> count;
        int ans = 0;
        
        while(r < n) {
            char c = s[r];
            maxx = max(maxx, ++count[c]);
            if(r - l + 1 - maxx > k) {
                maxx = max(maxx, -- count[s[l]]);
                l ++;
            }
            
            ans = max(ans, r - l + 1);
            
            r ++;
        }
        
        return ans;
    }
};