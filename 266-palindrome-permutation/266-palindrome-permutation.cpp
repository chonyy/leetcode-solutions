class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> count;
        
        for(char c : s) {
            count[c] ++;
        }
        
        bool seenOdd = false;
        
        for(auto entry : count) {
            if(entry.second % 2) {
                if(seenOdd)
                    return false;
                seenOdd = true;
            }
        }
        
        return true;
    }
};