class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int num = 0;
        int wordP = 0;
        int n = word.size();
        
        for(char c : abbr) {
            if(isdigit(c)) {
                if(num == 0 && c == '0')
                    return false;
                num = num * 10 + c - '0';
            }
            else {
                wordP += num;
                num = 0;
                
                if(word[wordP] != c) {
                    return false;
                }
                
                wordP ++;
            }
        }
        
        return true && num == n-wordP;
    }
};