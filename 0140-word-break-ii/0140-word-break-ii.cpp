class Solution {
public:
    unordered_map<string, vector<string>> mem;
    
    vector<string> backtrack(string s, unordered_set<string>& dict) {
        if(mem.find(s) != mem.end()) {
            return mem[s];
        }
        
        vector<string> ans;
        
        if(dict.count(s)) {
            ans.push_back(s);
        }
        
        for(int i = 0; i < s.size(); i ++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            
            if(dict.count(right) == 0) {
                continue;
            }
            
            auto leftAns = backtrack(left, dict);
            
            for(auto& l : leftAns) {
                ans.push_back(l + " " + right);
            }
        }
        
        return mem[s] = ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return backtrack(s, dict);
    }
};