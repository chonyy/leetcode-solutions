class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;

        for (string& str : strs) {
            group[sort(str)].push_back(str);
        }

        vector<vector<string>> res;

        for (auto& entry : group) {
            res.push_back(entry.second);
        }

        return res;
    }

    string sort(string& str) {
        vector<int> count(26);
        string copy = "";
        
        for (char c : str) {
            count[c - 'a'] ++;
        }

        for (int i = 0; i < 26; i ++) {
            while(count[i]) {
                copy += 'a' + i;
                count[i] --;
            }
        }

        return copy;
    }
};