class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(char c : t) {
            m[c] ++;
        }
        
        int n = s.size();
        int l = 0, r = 0;
        int ansStart = 0;
        int ans = INT_MAX;
        int counter = t.size();
        
        while(r < n) {
            // add new 
            if(m[s[r]] > 0) {
                counter --;
            }
            m[s[r]] --;
            
            // remove old
            while(counter == 0) { 
                int len = r - l + 1;
                if(len < ans) {
                    ans = len;
                    ansStart = l;
                }
                
                // make invalid
                if(m[s[l]] == 0) {
                    counter ++;
                }
                
                m[s[l]] ++;
                l ++;
            }
            r ++;
        }
        
        return ans == INT_MAX ? "" : s.substr(ansStart, ans);
    }
};