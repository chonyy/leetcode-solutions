class TrieNode {
public:
    bool isWord = false;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root = nullptr;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto cur = root;
        
        for(char c : word) {
            auto& children = cur->children;
            if(children.find(c) == children.end()) {
                children[c] = new TrieNode();
            }
            cur = children[c];
        }
        
        cur->isWord = true;
    }
    
    TrieNode* find(string prefix) {
        auto cur = root;
        
        for(char c : prefix) {
            auto& children = cur->children;
            if(children.find(c) == children.end()) {
                return nullptr;
            }
            cur = children[c];
        }
        
        return cur;
    }
    
    bool search(string word) {
        auto node = find(word);
        if(!node)
            return false;
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */