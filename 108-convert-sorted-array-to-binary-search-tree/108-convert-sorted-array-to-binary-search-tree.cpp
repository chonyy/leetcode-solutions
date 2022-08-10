/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convert(vector<int>& nums, int start, int end) {
        if(end < start) 
            return nullptr;
        
        int mid = start + (end - start) / 2;
        int val = nums[mid];
        TreeNode* newNode = new TreeNode(val);
        
        newNode->left = convert(nums, start, mid-1);
        newNode->right = convert(nums, mid+1, end);
        
        return newNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert(nums, 0, n-1);
    }
};