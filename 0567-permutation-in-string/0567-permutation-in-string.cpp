class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        unordered_map<char,int> count1;
        unordered_map<char,int> count2;
        int l = 0;
        int r = 0;

        for (char c : s1) {
            count1[c] ++;
        }

        while (r < s2.size()) {
            count2[s2[r]] ++;

            if (r - l + 1 == n) {
                if(count1 == count2) {
                    return true;
                }

                count2[s2[l]] --;
                if(count2[s2[l]] == 0) {
                    count2.erase(s2[l]);
                }
                l ++;
            }

            r ++;
        }

        return false;
    }
};