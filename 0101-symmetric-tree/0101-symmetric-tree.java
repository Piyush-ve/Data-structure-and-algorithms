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
    boolean helper(TreeNode root1,TreeNode root2)
    {
        if(root1==null&&root2==null)return true;

        if(root1==null||root2==null)return false;

        if(root1.val!=root2.val)return false;

        return (helper(root1.left,root2.right)&&helper(root1.right,root2.left));
    }
    public boolean isSymmetric(TreeNode root) {
        if(root==null)return true;

        TreeNode root1=root.left;
        TreeNode root2=root.right;

        return helper(root1,root2);
    }
}