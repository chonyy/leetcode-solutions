/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "#,";
        }

        string str = to_string(root->val) + ",";
        str += serialize(root->left) + serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return de(data, idx);
    }

    TreeNode* de(string& data, int& idx) {
        if (idx >= data.size()) {
            return nullptr;
        }

        if (data[idx] == '#') {
            idx += 2;
            return nullptr;
        }

        int num = 0;

        while (isdigit(data[idx])) {
            num = num * 10;
            num += data[idx] - '0';
            idx ++;
        }
        idx ++;

        TreeNode* node = new TreeNode(num);
        node->left = de(data, idx);
        node->right = de(data, idx);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;