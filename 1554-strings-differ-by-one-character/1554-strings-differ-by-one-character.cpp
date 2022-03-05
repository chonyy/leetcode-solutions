class Solution {
public:
    bool differByOne(vector<string>& dict) {
        int n = dict.size();
        int len = dict[0].size();
        
        for(int i = 0; i < len; i ++) {
            unordered_set<string> seen;
            for(auto& str : dict) {
                string sub = str.substr(0,i) + str.substr(i+1);
                if(seen.count(sub))
                    return true;
                seen.insert(sub);
            }
        }
        
        return false;
    }
};