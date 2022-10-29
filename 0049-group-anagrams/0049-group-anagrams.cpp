class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;

        for(string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }

        for(auto it = m.begin(); it != m.end(); it ++) {
            res.push_back(it->second);
        }

        return res;
    }
};