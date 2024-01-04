class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
        unordered_map<string, vector<string>> m;
        
        for(auto& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        
        for(auto i : m) {
            res.push_back(i.second);
        }
        
        return res;
    }
};