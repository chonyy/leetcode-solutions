class TrieNode {
    public:
        bool isWord;
        unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        
        for (char c : word) {
            auto& children = cur->children;
            
            // Create new node if not contains
            if (!children.contains(c)) {
                TrieNode* node = new TrieNode();
                children[c] = node;
            }

            cur = children[c];
        }

        // set final char to isWord = true
        cur->isWord = true;
    }
    
    bool search(string word) {
        // iterate with String
        // return false if stop in middle
        // return isWord

        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.contains(c)) {
                return false;
            }
            
            cur = cur->children[c];
        }

        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        // return false if start with middle
        // return node != nullptr

        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children.contains(c)) {
                return false;
            }
            
            cur = cur->children[c];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */