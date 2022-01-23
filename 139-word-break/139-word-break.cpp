class Solution {
public:
    bool canBreak(string& s, unordered_set<string>& dict, unordered_map<string,bool>& seen) {
        // check if seen
        if(seen.count(s)) {
            return seen[s];
        }
        
        // check if dict
        if(dict.find(s) != dict.end()) {
            return true;
        }
        
        // try splitting
        int n = s.size();
        for(int i = 0; i < n; i ++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if(dict.find(left) != dict.end() && canBreak(right, dict, seen)) {
                return seen[s] = true;
            }
        }
        
        return seen[s] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> seen;
        
        return canBreak(s, dict, seen);
    }
};