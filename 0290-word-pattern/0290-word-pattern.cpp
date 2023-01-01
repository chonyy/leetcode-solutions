class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string t;
        unordered_map<char, string> m;
        unordered_map<string, char> m2;
        int n = pattern.size();
        int i = 0;
        
        while(ss >> t) {
            char ch = pattern[i];
            if(m.count(ch) && m[ch] != t) {
                return false;
            }
            if(m2.count(t) && m2[t] != ch) {
                return false;
            }
            m[ch] = t;
            m2[t] = ch;
            
            i ++;
        }
        
        return i == n;
    }
};