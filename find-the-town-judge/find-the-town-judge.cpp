class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> s;
        
        if(n == 1)
            return 1;
        
        for(auto t : trust) {
            s[t[0]] --;
            s[t[1]] ++;
        }
        
        for(auto entry : s) {
            if(entry.second == n-1) {
                return entry.first;
            }
        }
        
        return -1;
    }
};