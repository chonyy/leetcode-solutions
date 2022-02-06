class Solution {
public:
    bool cmp(string& word1, string& word2, unordered_map<char,int>& m) {
        int i = 0;
        int j = 0;
        
        while(i < word1.size() && j < word2.size()) {
            char c1 = word1[i];
            char c2 = word2[j];
            
            if(c1 != c2) {
                return m[c1] < m[c2];
            }
            
            i ++;
            j ++;
        }
        
        return word2.size() >= word1.size();
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        unordered_map<char,int> m;
        
        for(int i = 0; i < 26; i ++) {
            m[order[i]] = i;
        }
        
        
        for(int i = 1 ; i < n ; i ++) {
            if(cmp(words[i-1], words[i], m) == false)
                return false;
        }
        
        return true;
    }
};