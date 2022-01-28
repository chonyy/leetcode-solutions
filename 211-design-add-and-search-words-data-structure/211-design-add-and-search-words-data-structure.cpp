class TrieNode {
    public:
        bool word;
        unordered_map<char, TrieNode*> m;
        TrieNode() {
            word = false;
        }
};

class WordDictionary {
public:
    TrieNode* trie = new TrieNode();
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* cur = trie;
        for(char c : word) {
            if(cur->m.count(c) == 0) {
                cur->m[c] = new TrieNode();
            }
            cur = cur->m[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return search(word, trie);
    }
    
    bool search(string word, TrieNode* root) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i ++) {
            char c = word[i];
            if(c == '.') {
                bool res = false;
                
                auto& children = cur->m;
                string sub = word.substr(i+1);
                for(auto child : children) {
                    if(search(sub, child.second))
                        return true;
                }
                
                return false;
            }
            
            if(cur->m.count(c) == 0)
                return false;
            cur = cur->m[c];
        }
        return cur->word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */