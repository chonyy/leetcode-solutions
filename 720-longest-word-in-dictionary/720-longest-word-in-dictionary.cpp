class TrieNode {
    public:
        string word;
        unordered_map<char,TrieNode*> children;
};

class Solution {
public:
    void insert(string& word) {
        auto cur = root;
        for(char c : word) {
            if(cur->children.count(c) == 0) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = word;
    }
    
    TrieNode* root;
        
    void dfs(TrieNode* root, string& res) {
        if(!root) {
            return;
        }
        
        auto& children = root->children;
        for(auto& entry : children) {
            auto& child = entry.second;
            // get ans
            if(child->word.size() != 0) {
                string& word = child->word;
                // cout << word << " " << res << endl;
                if(word.size() > res.size() || (word.size() == res.size() && word < res)) {
                    res = word;
                }
                
                dfs(child, res);
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        
        for(auto& word : words) {
            insert(word);
        }
        
        string res = "";
        dfs(root, res);
        return res;
    }
};