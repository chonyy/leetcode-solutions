class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        int n = s1.size();
        vector<char> cs;
        int j = 0;

        for(int i = 0; i < n; i ++) {
            if(s1[i] != s2[i]) {
                cs.push_back(i);
            }

            if(cs.size() > 2) {
                return false;
            }
        }
        
        return cs.size() == 0 || (cs.size() == 2 && s1[cs[0]] == s2[cs[1]] && s1[cs[1]] == s2[cs[0]]);
    }
};