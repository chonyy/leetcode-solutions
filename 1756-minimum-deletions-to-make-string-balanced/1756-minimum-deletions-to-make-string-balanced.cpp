class Solution {
public:
    int minimumDeletions(string s) {
        int rightA = 0;

        for(char c : s) {
            if(c == 'a') {
                rightA ++;
            }
        }

        int leftA = 0;
        int res = INT_MAX;
        int n = s.size();
        
        for(int i = 0; i < n; i ++) {
            int rightTotal = n - i;
            int rightB = rightTotal - rightA;
            int leftB = i - leftA;

            res = min(res, leftB + rightA);
            res = min(res, leftA + rightA);
            res = min(res, leftB + rightB);

            leftA += s[i] == 'a';
            rightA -= s[i] == 'a';
        }

        return res;
    }
};