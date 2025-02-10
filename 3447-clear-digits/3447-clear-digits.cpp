class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();

        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(isdigit(c)) {
                j --;
            }
            else {
                s[j] = s[i];
                j ++;
            }
        }

        return s.substr(0, j);
    }
};