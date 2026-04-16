class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* cur = root;
        for (char c : s) {
            if (!cur->children.contains(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
    }

    int findMaxLen(string s) {
        int len = 0;

        TrieNode* cur = root;
        for (char c : s) {
            if (!cur->children.contains(c)) {
                break;
            }
            cur = cur->children[c];
            len ++;
        }

        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie = Trie();

        for (int num : arr1) {
            trie.insert(to_string(num));
        }

        int res = 0;

        for (int num : arr2) {
            res = max(res, trie.findMaxLen(to_string(num)));
        }

        return res;
    }
};