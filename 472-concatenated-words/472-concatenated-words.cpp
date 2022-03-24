class Solution {
public:
    bool canBreak(string& word, unordered_set<string>& dict) {
        if(dict.size() == 0)
            return false;
        
        int n = word.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; i ++) {
            for(int j = i-1; j >= 0; j --) {
                if(dp[j] == false)
                    continue;
                
                string sub = word.substr(j, i-j);
                if(dict.count(sub)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.size() == 1) {
            return {};
        }        
        
        auto cmp = [](string& s1, string& s2) {
            return s1.size() < s2.size();
        };
        
        sort(words.begin(), words.end(), cmp);
        
        vector<string> res;
        unordered_set<string> dict;
        
        for(string& word : words) {
            if(canBreak(word, dict)) {
                res.push_back(word);
            }
            dict.insert(word);
        }
        
        return res;
    }
};