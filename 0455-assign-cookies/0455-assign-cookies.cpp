class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int childIndex = 0;
        int cookieIndex = 0;
        
        int n = g.size();
        int m = s.size();
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while(cookieIndex < m && childIndex < n) {
            int curCookie = s[cookieIndex];
            int curChildContent = g[childIndex];
            
            if(curCookie >= curChildContent) {
                childIndex ++; 
            }
            
            cookieIndex ++;
        }
        
        return childIndex;
    }
};