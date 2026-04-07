class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insertWord(string& word) {
        TrieNode* cur = root;

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
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        Trie trie = Trie();
        
        for (auto& w : wordDict) {
            trie.insertWord(w);
        }

        for (int i = 0; i < n; i ++) {
            if (!dp[i]) {
                continue;
            }

            // set all j to true if it's word according to trie
            TrieNode* cur = trie.root;
            for (int j = i; j < n; j ++) {
                if (!cur->children.contains(s[j])) {
                    break;
                }

                cur = cur->children[s[j]];
                
                if (cur->isWord) {
                    dp[j + 1] = true;
                }
            }
        }

        return dp[n];
    }
};

//  leetcode
// 100000000
// i

