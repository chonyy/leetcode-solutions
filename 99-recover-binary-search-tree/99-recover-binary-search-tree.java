/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode first = null, second = null, pre = null;
    
    private void dfs(TreeNode root) {
        if(root == null) {
            return;
        }
        
        dfs(root.left);
        
        if(first == null && pre.val > root.val) {
            first = pre;
        }
        if(first != null && pre.val > root.val) {
            second = root;
        }
        
        // System.out.println(root.val);
        pre = root;
        dfs(root.right);
    }
    
    public void recoverTree(TreeNode root) {
        pre = new TreeNode(Integer.MIN_VALUE);
        dfs(root);
        
        // System.out.println(first.val);
        // System.out.println(second.val);
        
        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }
}