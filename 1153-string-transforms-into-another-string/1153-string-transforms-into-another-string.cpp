class Solution {
public:
    bool canConvert(string str1, string str2) {
        unordered_map<char,char> mapping;
        unordered_set<char> used;
        int n = str1.size();
        
        if(str1 == str2)
            return true;
        
        for(int i = 0; i < n; i ++) {
            if(mapping.count(str1[i]) && mapping[str1[i]] != str2[i]) {
                return false;
            }
            mapping[str1[i]] = str2[i];
            used.insert(str2[i]);
        }
        
        return used.size() < 26;
    }
};