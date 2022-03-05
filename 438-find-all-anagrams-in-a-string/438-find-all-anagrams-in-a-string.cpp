class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> pMap;
        
        for(char c : p) {
            pMap[c] ++;
        }
        
        int l = 0, r = 0;
        int n = s.size();
        int m = p.size();
        unordered_map<char,int> sMap;
        vector<int> res;
        
        while(r < n) {
            // check for over extending
            if(r - l + 1 > m) {
                sMap[s[l]] --;
                if(sMap[s[l]] == 0)
                    sMap.erase(s[l]);
                
                l ++;
            }
            sMap[s[r]] ++;
            // collect answer
            if(sMap == pMap) {
                res.push_back(l);
            }
            r ++;
        }
        return res;
    }
};