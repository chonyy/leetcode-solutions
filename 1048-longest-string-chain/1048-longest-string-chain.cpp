class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort the words
        auto compare = [](const string &s1, const string &s2) {
            return s1.length() < s2.length();
        };
        
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        
        // check all pre
        for(string& w : words) {
            int n = w.size();
            for(int i = 0; i < n; i ++) {
                string pre = w.substr(0,i) + w.substr(i+1);
                dp[w] = max(dp[w], dp[pre] + 1);
            }
            res = max(res, dp[w]);
        }
        // +1 if present
        // cal max
        
        return res;
    }
};