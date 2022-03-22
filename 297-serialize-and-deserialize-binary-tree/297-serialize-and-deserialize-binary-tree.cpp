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
        if(!root)
            return "#";
        
        string encoded = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string temp;
        queue<string> q;
        
        while(getline(ss, temp, ',')) {
            q.push(temp);
        }
        
        return de(q);
    }
    
    TreeNode* de(queue<string>& q) {
        string cur = q.front();
        q.pop();
        
        if(cur == "#") {
            return nullptr;
        }
        
        TreeNode* newNode = new TreeNode(stoi(cur));
        newNode->left = de(q);
        newNode->right = de(q);
        
        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));