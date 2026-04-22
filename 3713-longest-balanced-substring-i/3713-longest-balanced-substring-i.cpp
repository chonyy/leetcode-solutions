class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        for (int i = 0; i < n; i ++) {
            unordered_map<char,int> count;
            int maxF = 0;
            int unique = 0;
            int maxCount = 0;
            for (int j = i; j < n; j ++) {
                count[s[j]] ++;

                if (count[s[j]] == 1) {
                    unique ++;
                }

                if (count[s[j]] > maxF) {
                    maxF = count[s[j]];
                    maxCount = 1;
                }
                else if (count[s[j]] == maxF) {
                    maxCount ++;
                }


                if (unique == maxCount) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};

// abbac
//    i

// count:
// a: 2
// b: 2

// maxF = 2
// unique = 2
// maxFCount = 2

// if unique == maxFount:
//     res = 4