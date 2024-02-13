class Solution {
public:
    bool isPal(string s) {
        int n = s.size();
        int l = 0;
        int r = n -1;
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l ++;
            r --;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        
        for(auto w : words) {
            if(isPal(w)) {
                return w;
            }
        }
        
        return "";
    }
};