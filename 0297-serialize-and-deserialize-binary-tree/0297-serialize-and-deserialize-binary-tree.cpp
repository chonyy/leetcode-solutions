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
        string str = "";
        ser(str, root, true);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return des(data, idx);
    }

    TreeNode* des(string& data, int& idx) {
        if (idx >= data.size()) {
            return nullptr;
        }

        if (data[idx] == '#') {
            idx += 2;
            return nullptr;
        }

        int num = 0;
        bool negative = false;
        while (idx < data.size() && (isdigit(data[idx]) || data[idx] == '-')) {
            if (data[idx] == '-') {
                negative = true;
                idx ++;
                continue;
            }

            num = num * 10;
            num += data[idx] - '0';
            idx ++;
        }
        idx ++;

        if (negative) {
            num = -num;
        }

        TreeNode* node = new TreeNode(num);
        node->left = des(data, idx);
        node->right = des(data, idx);

        return node;
    }

    void ser(string& str, TreeNode* node, bool first) {
        if (!first) {
            str += ",";
        }

        if (!node) {
            str += "#";
            return;
        }

        str += to_string(node->val);
        ser(str, node->left, false);
        ser(str, node->right, false);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));