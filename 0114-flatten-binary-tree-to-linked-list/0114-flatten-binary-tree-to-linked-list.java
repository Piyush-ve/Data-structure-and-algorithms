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

    ArrayList<TreeNode>in=new ArrayList<>();
    public void inorder(TreeNode root)
    {
        if(root==null)
        {
            return;
        }

       
        in.add(root);
        inorder(root.left);
        inorder(root.right);
    }
    public void flatten(TreeNode root) {

         inorder(root);
        int n=in.size();
        TreeNode curr=root;
        

        for(int i=1;i<n;i++)
        {
            curr.left=null;
            curr.right=in.get(i);

            curr=curr.right;
        }
        

        return ;
    }
}