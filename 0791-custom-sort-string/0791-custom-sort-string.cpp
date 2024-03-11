class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        
        for(char c : s) {
            m[c] ++;
        }
        
        string res = "";
        for(char c : order) {
            if(m[c]) {
                res.append(m[c], c);
                m[c] = 0;
            }
        }
        
        for(auto entry : m) {
            if(entry.second > 0) {
                res.append(entry.second, entry.first);
            }
        }
        
        return res;
    }
};