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

    void addWord(string& s) {
        TrieNode* cur = root;

        for (char c : s) {
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
    unordered_map<int,int> cache;

    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie = Trie();

        for (string& word : dictionary) {
            trie.addWord(word);
        }

        return getExtra(s, 0, trie.root);
    }

    int getExtra(string& s, int idx, TrieNode* root) {
        if(idx == s.size()) {
            return 0;
        }
        if (cache.contains(idx)) {
            return cache[idx];
        }

        int res = s.size() - idx;
        res = min(res, 1 + getExtra(s, idx+1, root));

        TrieNode* cur = root;
        for (int i = idx; i < s.size(); i ++) {
            if (!cur->children.contains(s[i])) {
                break;
            }

            cur = cur->children[s[i]];
            if (cur->isWord) {
                res = min(res, getExtra(s, i+1, root));
            }
        }

        cache[idx] = res;
        return res;
    }
};