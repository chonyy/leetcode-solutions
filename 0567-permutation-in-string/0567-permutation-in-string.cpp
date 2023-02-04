class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        
        int n = s1.size();
        int m = s2.size();
        int i = 0, j = 0;
        
        while(i < n) {
            map1[s1[i]] ++;
            i ++;
        }
        
        i = 0;
        while(j < m) {
            if(j - i + 1 > n) {
                map2[s2[i]] --;
                if(map2[s2[i]] == 0) {
                    map2.erase(s2[i]);
                }
                i ++;
                continue;
            }
            
            map2[s2[j]] ++;
            if(map1 == map2) {
                return true;
            }
            j ++;
            
        }
        
        return false;
    }
};