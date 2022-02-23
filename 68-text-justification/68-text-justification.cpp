class Solution {
public:
    int calWords(vector<string>& words, int cur, int maxWidth) {
        int occupy = 0;
        int fits = 0;
        
        while(cur < words.size()) {
            occupy += words[cur].size();
            if(occupy > maxWidth)
                break;
            occupy ++;
            
            fits ++;
            cur ++;
        }
        
        return fits;
    }
    
    string leftJust(vector<string>& words, int cur, int fits, int maxWidth) {
        string res = "";
        bool first = true;
        
        for(int i = 0; i < fits; i ++) {
            if(i != 0)
                res += " ";
            
            res += words[cur + i];
        }
        
        // append remain spaces
        int size = res.size();
        int remain = maxWidth - size;
        res.append(remain, ' ');
        
        return res;
    }
    
    string midJust(vector<string>& words, int cur, int fits, int maxWidth) {
        int size = 0;
        for(int i = 0; i < fits; i ++) {
            size += words[cur + i].size();
        }
        
        int spaces = maxWidth - size;
        int remain = fits == 1 ? spaces : spaces % (fits - 1);
        int gap = fits == 1 ? spaces : spaces / (fits - 1);
        
        string res = "";
        
        for(int i = 0; i < fits; i ++) {
            if(i != 0) {
                res.append(gap, ' ');
                if(remain) {
                    res += ' ';
                    remain --;
                }
            }
            res += words[cur + i]; 
        }
        
        return res;
    }
               
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        int i = 0;
        
        while(i < n) {
            // how many words
            int fits = calWords(words, i, maxWidth);
            // cout << fits << endl;
            
            // check last or not
            if(i + fits == n || fits == 1) { // left justify
                string lefted = leftJust(words, i, fits, maxWidth);
                res.push_back(lefted);
            }
            else {
                // calculate space in between
                // append space
                string mid = midJust(words, i, fits, maxWidth);
                res.push_back(mid);
            }
            i += fits;
        }
        return res;
    }
};


// check how many words could fit
// calculate space between
// handle special case for last
