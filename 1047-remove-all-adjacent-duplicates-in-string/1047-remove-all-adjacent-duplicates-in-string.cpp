class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0, j = 0;
        int n = s.size();
        
        while(j < n) {
            s[i] = s[j];
            if(i > 0 && s[i] == s[i-1]) {
                i -= 2;
            }
            j ++;
            i ++;
        }
        
        return s.substr(0, i);
    }
};

//           x
// cur: abbaca

//        j
// temp: cab