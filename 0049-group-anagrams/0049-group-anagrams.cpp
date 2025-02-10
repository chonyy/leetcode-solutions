class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;

        for(auto& s : strs) {
            m[sort(s)].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& entry : m) {
            res.push_back(entry.second);
        }

        return res;
    }

    string sort(string& s) {
        string copy = "";

        vector<int> count(26, 0);

        for(char c : s) {
            count[c - 'a'] ++;
        }

        for(int i = 0; i < 26; i ++) {
            copy += string(count[i], 'a' + i);
        }

        return copy;
    }
};