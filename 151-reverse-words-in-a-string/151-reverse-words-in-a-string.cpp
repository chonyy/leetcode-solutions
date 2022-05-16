class Solution {
public:
    string reverseWords(string s) {
        // Reverse the sentence
        reverse(s.begin(), s.end());

        int wordStart = 0;
        int wordEnd = 0;
        int n = s.size();

        while(wordStart < n) {
            // Skip all the spaces
            while(wordStart < n && s[wordStart] == ' ')
                wordStart ++;

            if(wordStart < n && wordEnd > 0)
                s[wordEnd ++] = ' ';
                
            // Skip all the non spaces
            int start = wordEnd;
            while(wordStart < n && s[wordStart] != ' ') {
                s[wordEnd++] = s[wordStart ++];
            }

            // Revese the word
            reverse(s.begin() + start, s.begin() + wordEnd);
        }

        s.resize(wordEnd);
        return s;
    }
};