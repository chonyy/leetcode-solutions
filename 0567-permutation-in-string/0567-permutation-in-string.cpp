class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> count;
        for (char c : s1) {
            count[c] ++;
        }

        int n = s2.size();
        int l = 0;
        int r = 0;

        while (r < n) {
            if (r - l == s1.size()) {
                count[s2[l]] ++;
                if (count[s2[l]] == 0) {
                    count.erase(s2[l]);
                }
                l ++;
            }

            count[s2[r]] --;
            if (count[s2[r]] == 0) {
                count.erase(s2[r]);
            }

            // for (auto& entry : count) {
            //     cout << entry.first << " " << entry.second << endl;
            // }
            // cout << endl;

            if (count.empty()) {
                return true;
            }

            r ++;
        }

        return false;
    }
};