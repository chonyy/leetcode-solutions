class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int l = 0;
        int r = n-1;

        while (l < r) {
            // find vowel from left
            while (l < r && !vowels.contains(tolower(s[l]))) {
                l ++;
            }

            // find vowel from right
            while (l < r && !vowels.contains(tolower(s[r]))) {
                r --;
            }

            // swap and move
            swap(s[l], s[r]);
            l ++;
            r --;
        }
        
        return s;
    }
};