class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> count;

        for (char c : p) {
            count[c] ++;
        }

        int l = 0;
        int r = 0;
        int n = s.size();
        vector<int> res;

        while (r < n) {
            if (r - l == p.size()) {
                count[s[l]] ++;
                if (count[s[l]] == 0) {
                    count.erase(s[l]);
                }
                l ++;
            }

            count[s[r]] --;
            if (count[s[r]] == 0) {
                count.erase(s[r]);
            }

            // for (auto& entry : count) {
            //     cout << entry.first << " " << entry.second << endl;
            // }
            // cout << endl;

            if (count.size() == 0) {
                res.push_back(r - p.size() + 1);
            }

            r ++;
        }

        return res;
    }
};