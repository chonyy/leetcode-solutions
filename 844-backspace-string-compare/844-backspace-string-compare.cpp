class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        int p1 = n-1;
        int p2 = m-1;
        
        int skipS = 0;
        int skipT = 0;
        
        while(p1 >= 0 || p2 >= 0) {
            while(p1 >= 0) {
                if(s[p1] == '#') {
                    p1 --;
                    skipS ++;
                }
                else if(skipS > 0) {
                    skipS --;
                    p1 --;
                }
                else {
                    break;
                }
            }    
            
            while(p2 >= 0) {
                if(t[p2] == '#') {
                    p2 --;
                    skipT ++;
                }
                else if(skipT > 0) {
                    p2 --;
                    skipT --;
                }
                else {
                    break;
                }
            }
            
            if((p1 >= 0) != (p2 >= 0)) {
                return false;
            }
            if(p1 >= 0 && p2 >= 0 && s[p1] != t[p2]) {
                return false;
            }
            
            cout << p1 << " " << p2 << endl;
            if(p1 >= 0 && p2 >= 0)
                cout << s[p1] << " " << t[p2] << endl;
            
            p1 --;
            p2 --;
        }
        
        return true;
    }
};