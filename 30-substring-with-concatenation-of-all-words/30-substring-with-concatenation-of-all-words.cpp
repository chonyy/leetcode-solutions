class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt; // Expected times of each word
        for(auto &w : words) cnt[w]++;
        int n = words.size();
        int k = words[0].size();
        vector<int> res;
        for(int i = 0; i + n * k <= s.size(); i++){
            unordered_map<string, int> seen; // Visited times of each word during the loop starting from i
            for(int j = 0; j < n; j++){
                string str = s.substr(i + j * k, k); 
                seen[str]++;
                if(seen[str] > cnt[str]) break; // If for any words, visited times > expected times, then we stop the check.  
                if(j == n - 1) res.push_back(i);  // If all pass, we know i is one of the valid start index.
            }
        }
        return res;
    }
};