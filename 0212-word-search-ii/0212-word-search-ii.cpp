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
            root->isWord = false;
        }
    
        void addWord(string& s) {
            TrieNode* cur = root;
            
            for(char c: s) {
                // create node if not exist
                if(cur->children.find(c) == cur->children.end()) {
                    TrieNode* newNode = new TrieNode();
                    cur->children[c] = newNode;
                }
                // move node
                cur = cur->children[c];
            }
            
            cur->isWord = true;
        }
};

class Solution {
public:
    int rows;
    int cols;
    
    void search(vector<vector<char>>& board, int row, int col, TrieNode* root, vector<string>& res, string& cur) {
        // boundary check
        if(row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }
        
        char c = board[row][col];
        TrieNode* child = root->children[c];
        
        // leave if no children
        if(!child) {
            return;
        }
        
        cur = cur + c;
        
        // if is word
        //      put in container
        //      set isWord = false;
        if(child->isWord) {
            res.push_back(cur);
            child->isWord = false;
        }
        
        // backtracking
        board[row][col] = '#';
        search(board, row+1, col, child, res, cur);
        search(board, row-1, col, child, res, cur);
        search(board, row, col+1, child, res, cur);
        search(board, row, col-1, child, res, cur);
        board[row][col] = c;
        
        cur.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie trie = Trie();
        
        for(string& word : words) {
            trie.addWord(word);
        }
        
        rows = board.size();
        cols = board[0].size();
        string cur = "";
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                search(board, i, j, trie.root, res, cur);
            }
        }
        
        return res;
    }
};