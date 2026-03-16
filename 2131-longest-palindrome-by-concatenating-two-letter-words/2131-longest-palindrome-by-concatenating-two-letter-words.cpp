class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> count;
        bool alone = false;

        for (auto& w : words) {
            count[w] ++;
        }

        int res = 0;
        for (auto& w : words) {
            if (w[0] == w[1]) {
                if (count[w] >= 2) {
                    res += 4;
                    count[w] -= 2;
                }
                else if (count[w] == 1) {
                    alone = true;
                }
            }
            else {
                string target = w;
                reverse(target.begin(), target.end());
                if (count[target] && count[w]) {
                    res += 4;
                    count[w] --;
                    count[target] --;
                }
            }
        }

        if (alone) {
            res += 2;
        }

        return res;
    }
};