class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        
        for(char c : s) {
            count[c] ++;
        }
        
       int n = s.size();
        unordered_map<int, vector<char>> bucket;
        for(auto entry : count) {
            bucket[entry.second].push_back(entry.first);
        }
        
        string ans = "";
        for(int i = n; i >= 0; i --) {
            int freq = i;
            auto& toappend = bucket[i];
            for(auto c : toappend) {
                ans.append(freq, c);
            }
        }
        
        return ans;
    }
};