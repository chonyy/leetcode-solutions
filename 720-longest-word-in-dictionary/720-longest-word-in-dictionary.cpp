class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        
        unordered_set<string> visited;
        string ans = "";
        
        for(auto& word : words) {
            string pre = word.substr(0, word.size()-1);
            if(word.size() == 1 || visited.count(pre)) {
                visited.insert(word);
                if(word.size() > ans.size()) {
                    ans = word;
                }
            }
        }
        
        return ans;
    }
};