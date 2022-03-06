class Solution {
public:
    int hash(string& word) {
        int mask = 0;
        
        for(char c : word) {
            mask ^= (1 << (c - 'a'));
        }
        
        return mask;
    }
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> seen;
        
        for(auto& word : startWords) {
            seen.insert(hash(word));
        }
        
        int res = 0;
        
        for(auto& word : targetWords) {
            int h = hash(word);
            for(char c : word) {
                int newH = h ^ (1 << (c - 'a'));
                if(seen.count(newH)) {
                    res ++;
                    break;
                }
            }
        }
        
        return res;
    }
};