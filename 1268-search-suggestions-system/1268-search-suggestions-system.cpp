class TrieNode {
    public:
        vector<string> words;
        unordered_map<char, TrieNode*> children;
};

class Solution {
public:
    TrieNode* root;
    
    void insert(string& word) {
        auto cur = root;
        for(char c : word) {
            if(cur->children.count(c) == 0) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
            
            if(cur->words.size() < 3) {
                cur->words.push_back(word);
            }
        }
    }
    
    Solution() {
        root = new TrieNode();
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
    
        for(auto& p : products) {
            insert(p);
        }
        
        // get res
        auto cur = root;
        vector<vector<string>> res;
        int filled = 0;
        for(char c : searchWord) {
            cur = cur->children[c];
            if(!cur)
                break;
            
            res.push_back(cur->words);
            filled ++;
        }
        
        while(filled < searchWord.size()) {
            res.push_back({});
            filled ++;
        }
        
        return res;
    }
};