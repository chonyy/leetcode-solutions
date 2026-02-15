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
        
        void addWord(string& word) {
            auto cur = root;

            for (char c : word) {
                if (!cur->children.contains(c)) {
                    cur->children[c] = new TrieNode();
                }

                cur = cur->children[c];
            }
            cur->isWord = true;
        }
};

class Solution {
public:
    int rows;
    int cols;
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie = Trie();

        for (string& word : words) {
            trie.addWord(word);
        }

        unordered_set<string> res;
        rows = board.size();
        cols = board[0].size();
        string temp = "";

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                char c = board[i][j];
                find(res, temp, board, i, j, trie.root);
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void find(unordered_set<string>& res,
          string& temp,
          vector<vector<char>>& board,
          int r, int c,
          TrieNode* node) {

        // 1️⃣ boundary check
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;

        char ch = board[r][c];

        // 2️⃣ visited check
        if (ch == '#')
            return;

        // 3️⃣ trie check
        if (!node->children.contains(ch))
            return;

        // move to child
        node = node->children[ch];

        // process
        temp += ch;
        board[r][c] = '#';

        if (node->isWord) {
            res.insert(temp);
        }

        for (auto& dir : dirs) {
            find(res, temp, board, r + dir.first, c + dir.second, node);
        }

        temp.pop_back();
        board[r][c] = ch;
    }
};


// o a
// e t

// * -> o -> a

// 0, 0 
// *